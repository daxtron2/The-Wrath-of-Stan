#include "AppClass.h"
using namespace Simplex;
void Application::InitVariables(void)
{
	m_sProgrammer = "The Wrath of Stan\n\nDe George, Max - mtd3442@rit.edu\nKaushik, Rohit - rgk8966@rit.edu\nPaseltiner, Matthew - mjp3591@rit.edu\nWolschon, TJ - tjw3948@rit.edu";

	m_pLightMngr->SetPosition(vector3(0.0f, 7.0f, 13.0f), 1); //set the position of first light (0 is reserved for ambient light)

	m_pEntityMngr = MyEntityManager::GetInstance();

	m_pCamera = new MyCamera();

	// setup the room
	SetupRoom();

	// create and add the punc entity
	m_pEntityMngr->AddEntity(new MyEntity(IDENTITY_M4, "Punch"));
	m_pPunchEnt = m_pEntityMngr->GetEntity();
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pPunchEnt->GetRigidBody()->SetVisibleARBB(false);
	m_uPunchEntityId = m_pEntityMngr->GetEntityIndex("Punch");

	if (m_bOctreeActive)
	{
		m_pRoot = new MyOctant(m_uOctantLevels, m_uIdealEntityCount);
		m_pEntityMngr->Update();
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	//Update Entity Manager
	m_pEntityMngr->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
	
	//Get a timer
	static float fTimer = 0;	//store the new timer
	static uint uClock = m_pSystem->GenClock(); //generate a new clock for that timer
	fTimer += m_pSystem->GetDeltaTime(uClock); //get the delta time for that timer
	if (m_bOctreeActive)
	{
		if (static_cast<int>(fTimer) > 1.0f)
		{
			SafeDelete(m_pRoot);
			m_pRoot = new MyOctant(m_uOctantLevels, m_uIdealEntityCount);
			fTimer = 0;
		}
	}

	matrix4 punchBox = glm::inverse(m_pCamera->GetViewMatrix());
	matrix4 offsetMatrix = glm::translate(IDENTITY_M4, vector3(0.0f, 0.0f, -0.8f));
	punchBox = punchBox * glm::scale(vector3(.5f, .5f, 0.9f)) * offsetMatrix;
	m_pPunchEnt->SetModelMatrix(punchBox);
	m_pPunchEnt->SetMass(15001.f);

	if (m_bPunching)
		Punch();

	vector3 v3BoxPosition = m_pCameraMngr->GetForward() + m_pCameraMngr->GetPosition();
	//v3BoxPosition = * 1.5f;

	//std::cout << v3BoxPosition.x << std::endl;
	//std::cout << v3BoxPosition.y << std::endl;
	//std::cout << v3BoxPosition.z << std::endl;

	MoveFrontEntity(v3BoxPosition);

	
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	if (m_bOctreeActive)
		m_pRoot->Display();
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
		
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();
	

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	

	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}

void Application::Release(void)
{
	if (m_bOctreeActive)
		SafeDelete(m_pRoot);
	SafeDelete(m_pCamera);

	//release GUI
	ShutdownGUI();
}

void Application::MoveFrontEntity(vector3 position)
{
	matrix4 test = glm::translate(position);
	test = test * glm::scale(vector3(.3f, .3f, .3f));

	if (m_pFrontEntity == nullptr)
	{
		//std::cout << "IN" << std::endl;

		int frontEndId = m_pEntityMngr->GetEntityIndex("Front");

		if (frontEndId != -1)
		{
			m_pFrontEntity = m_pEntityMngr->GetEntity(frontEndId);
		}
		else
		{
			//matrix4 m4FrontEntity = IDENTITY_M4;
			//m4FrontEntity = m4FrontEntity * glm::translate(position);
			//m4FrontEntity = m4FrontEntity * glm::scale(vector3(2.f, 2.f, 2.f));
			m_pEntityMngr->AddEntity(new MyEntity(test, "Front"));
			m_pEntityMngr->UsePhysicsSolver(true);
			m_pEntityMngr->SetMass(15001.f);
		}
	}
	else
	{
		//std::cout << "OUT" << std::endl;
		m_pFrontEntity->SetModelMatrix(test);
		//std::cout << "ENT LOCATION: " << m_pFrontEntity->GetPosition().x << " " << m_pFrontEntity->GetPosition().y << " " << m_pFrontEntity->GetPosition().z << std::endl;
		//m_pEntityMngr->RemoveEntity(m_pEntityMngr->GetEntityIndex("Front"));

	}

}
void Application::Punch(void)
{
	int colCount = m_pPunchEnt->GetCollidingCount();
	if (0 == colCount)
		return;

	uint entityCount = m_pEntityMngr->GetEntityCount();
	std::vector<MyEntity*> colEntities;

	//needs a more optimal way to only get things collided with this
	for (int i = 0; i < entityCount; i++)
	{
		if (i == m_uPunchEntityId) continue;
		MyEntity* temp = m_pEntityMngr->GetEntity(i);
		if(m_pPunchEnt->IsColliding(temp))
		{
			colEntities.push_back(temp);
		}
	}

	for (int i = 0; i < colEntities.size(); i++)
	{
		vector3 otherPos = colEntities[i]->GetPosition();
		colEntities[i]->GetRigidBody()->SetColorOutline(C_BLUE);
		vector3 playerPos = m_pCameraMngr->GetPosition();
		vector3 punchDir = glm::normalize(otherPos - playerPos);
		colEntities[i]->ApplyForce(punchDir * m_fPunchForce);
	}

	// prevent calling the method again
	m_bPunching = false;
}

void Application::SetRow(vector3 origin)
{
	matrix4 deg90Y = glm::rotate(glm::radians(90.0f), AXIS_Y);
	matrix4 deg180X = glm::rotate(glm::radians(0.0f), AXIS_X);
	matrix4 degN90Y = glm::rotate(glm::radians(-90.0f), AXIS_Y);
	matrix4 m4Position;

	vector3 deskPosition = origin;
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	MyEntity* desk = m_pEntityMngr->GetEntity();
	m4Position = glm::translate(deskPosition);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(5.f);

	vector3 chair1Offset = vector3(.5f, 0, 1);
	vector3 chair1Position = chair1Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	m4Position = glm::translate(chair1Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(2.5f);	
	

	vector3 chair2Offset = vector3(-.5f, 0, 1);
	vector3 chair2Position = chair2Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	m4Position = glm::translate(chair2Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(2.5f);


	vector3 computer1Offset = vector3(-.87f, 1.1f, 0);
	vector3 computer1Position = computer1Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	m4Position = glm::translate(computer1Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.5f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());

	vector3 computer2Offset = vector3(.87f, 1.1f, 0);
	vector3 computer2Position = computer2Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	m4Position = glm::translate(computer2Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.5f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());

	vector3 monitor1Offset = vector3(.4f, 1.1f, -.2f);
	vector3 monitor1Position = monitor1Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	m4Position = glm::translate(monitor1Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());

	vector3 monitor2Offset = vector3(-.4f, 1.1f, -.2f);
	vector3 monitor2Position = monitor2Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	m4Position = glm::translate(monitor2Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());

	vector3 keyboard1Offset = vector3(-.4f, 1.1f, 0.2f);
	vector3 keyboard1Position = keyboard1Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	m4Position = glm::translate(keyboard1Position);
	m4Position = m4Position * degN90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());

	vector3 keyboard2Offset = vector3(.4f, 1.1f, 0.2f);
	vector3 keyboard2Position = keyboard2Offset + origin;
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	m4Position = glm::translate(keyboard2Position);
	m4Position = m4Position * degN90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(.3f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());
}

void Application::SpawnPin(void) 
{
	MyEntity* pin = new MyEntity("Stan\\StenPin.obj", "Pin");
	pin->UsePhysicsSolver(true);
	pin->SetMass(10.0f);
	pin->SetPosition(m_pEntityMngr->GetEntity(m_pEntityMngr->GetEntityIndex("Front"))->GetPosition());
	/*matrix4 pinMatrix = pin->GetModelMatrix();
	matrix4 rotateMatrix = glm::rotate(glm::dot(m_pCamera->GetForward(), AXIS_Z), AXIS_Y);
	pinMatrix = pinMatrix * rotateMatrix;
	pin->SetModelMatrix(pinMatrix);*/

	m_pEntityMngr->AddEntity(pin);

	pin->ApplyForce(glm::normalize(m_pCamera->GetTarget() - m_pCamera->GetPosition()) * 10.0f);
}

void Application::SetupRoom(void)
{
	vector3 v3Position = vector3(0.0f);
	matrix4 m4Position = IDENTITY_M4;

	//rotation matrices for the various items
	matrix4 deg90Y = glm::rotate(glm::radians(90.0f), AXIS_Y);
	matrix4 deg180X = glm::rotate(glm::radians(0.0f), AXIS_X);
	matrix4 degN90Y = glm::rotate(glm::radians(-90.0f), AXIS_Y);

	m_pMeshMngr->AddCubeToRenderList(glm::translate(vector3(0,1,0)), C_YELLOW);

#pragma region Player
	//Player
	m_pEntityMngr->AddEntity("Stan\\StenPin.obj", "Player");
	m_pEntityMngr->RemoveEntity("Player");

	m_pCamera->SetPositionTargetAndUpward(
		vector3(0, 1.8f, 0.f), //Camera position
		vector3(0, 1.8f, -2.5f), //What I'm looking at
		AXIS_Y); //What is up my dude

	m_pCameraMngr->SetProjectionMatrix(m_pCamera->GetProjectionMatrix());
	m_pCameraMngr->SetViewMatrix(m_pCamera->GetViewMatrix());

	m_pCameraMngr->SetForward(m_pCamera->GetForward());
	m_pCameraMngr->SetRightward(m_pCamera->GetRightward());
	m_pCameraMngr->SetPositionTargetAndUpward(
		m_pCamera->GetPosition(),
		m_pCamera->GetTarget(),
		m_pCamera->GetUpward()
	);

#pragma endregion


	//doesn't work right now
#pragma region Walls and Floor

	m_pEntityMngr->AddEntity("Stan\\Floor.obj", "Floor");
	v3Position = vector3(0.f, -0.5f, 0.f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::scale(vector3(2, 1, 2));
	//m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	//m_pEntityMngr->SetMass(12345.f);

	m_pEntityMngr->AddEntity("Stan\\Floor.obj", "Ceiling");
	v3Position = vector3(0.f, 5.f, 0.f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::scale(vector3(2, 1, 2));
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr->AddEntity("Stan\\Wall.obj", "LeftWall");
	v3Position = vector3(-7.5f, 0, 0);
	m4Position = glm::translate(v3Position);
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(12345.f);

	m_pEntityMngr->AddEntity("Stan\\Wall.obj", "RightWall");
	v3Position = vector3(5.5f, 0, 0);
	m4Position = glm::translate(v3Position);
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(12345.f);

	m_pEntityMngr->AddEntity("Stan\\SmWall.obj", "BackWall");
	v3Position = vector3(-0.5f, 0, 8.f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::scale(vector3(2, 1, 1));
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(12345.f);

	m_pEntityMngr->AddEntity("Stan\\SmWall.obj", "FrontWall");
	v3Position = vector3(-0.5f, 0, -8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::scale(vector3(2, 1, 1));
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(12345.f);

#pragma endregion

	for (int z = -1; z < 3; z++) 
	{
		for (int x = -3; x < -1; x++) 
		{
			SetRow(vector3(x*2, 0, z*3));
		}
	}

	for (int z = -1; z < 3; z++)
	{
		for (int x = 1; x < 3; x++)
		{
			SetRow(vector3(x*2, 0, z*3));
		}
	}

#pragma region Alberto Territory
	//Desk

	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	MyEntity* desk = m_pEntityMngr->GetEntity();
	v3Position = vector3(-4.00f, 0.0f, -4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * deg90Y;
	m4Position = m4Position * deg180X;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(5.f);

	//Keyboards

	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-4.05, 1.1f, -4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * deg90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());



	//Monitors

	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-4.05, 1.1f, -3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * degN90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());


	//Computer Towers

	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-4.75f, 1.1f, -4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * deg90Y;
	m4Position = m4Position * deg180X;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(1.5f);
	m_pEntityMngr->GetEntity()->GetSolver()->SetDesk(desk->GetRigidBody());


	//Chairs

	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-4.05f, 0, -5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * degN90Y;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(2.5f);

#pragma endregion

#pragma region Back Desk
	//Back Desk

	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-1.f, 0.0f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * deg90Y;
	m4Position = m4Position * deg180X;
	m_pEntityMngr->UsePhysicsSolver(m_bEnablePropPhysics);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->SetMass(5.f);
#pragma endregion
}


void Application::DeleteEntities(void)
{
	int entityCount = m_pEntityMngr->GetEntityCount();
	for (int x = 0; x < entityCount; x++)
	{
		m_pEntityMngr->RemoveEntity(m_pEntityMngr->GetUniqueID(x));
	}
}
