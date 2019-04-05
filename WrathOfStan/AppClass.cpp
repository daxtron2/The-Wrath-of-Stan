#include "AppClass.h"
using namespace Simplex;
void Application::InitVariables(void)
{
	m_sProgrammer = "De George, Max - mtd3442@rit.edu\nKaushik, Rohit - rgk8966@rit.edu\nPaseltiner, Matthew - mjp3591@rit.edu\nWolschon, TJ - tjw3948@rit.edu";

	//Set the position and target of the camera
	m_pCameraMngr->SetPositionTargetAndUpward(
		vector3(0.0f, 5.0f, 25.0f), //Position
		vector3(0.0f, 0.0f, 0.0f),	//Target
		AXIS_Y);					//Up

	m_pLightMngr->SetPosition(vector3(0.0f, 3.0f, 13.0f), 1); //set the position of first light (0 is reserved for ambient light)

	//m_pEntityMngr = MyEntityManager::GetInstance(); //Initialize the entity manager
	//m_pEntityMngr->AddEntity("Minecraft\\Steve.obj", "Steve");
	//m_pEntityMngr->UsePhysicsSolver();

	vector3 v3Position = vector3(0.0f);
	matrix4 m4Position = IDENTITY_M4;

#pragma region 1st Row
	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-5.05f, 0.0f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-5.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-4.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-5.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-4.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-5.75f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-4.35f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-5.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-4.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-3.0f, 0.0f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-3.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-2.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-3.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-2.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-3.70f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-2.30f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-3.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-2.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Center Aisle

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(2.0f, 0.0f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(1.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(2.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(1.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(2.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(1.3f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(2.70f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(1.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(2.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(4.05f, 0.0f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(3.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(4.55, 0.08f, 10.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(3.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(4.55, 0.06f, 9.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(3.35f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(4.75f, -.7f, 10.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(3.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(4.55f, -.35f, 11.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);
#pragma endregion

#pragma region 2nd Row
	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-5.05f, 0.0f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-5.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-4.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-5.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-4.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-5.75f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-4.35f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-5.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-4.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-3.0f, 0.0f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-3.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-2.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-3.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-2.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-3.70f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-2.30f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-3.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-2.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Center Aisle

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(2.0f, 0.0f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(1.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(2.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(1.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(2.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(1.3f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(2.70f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(1.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(2.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(4.05f, 0.0f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(3.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(4.55, 0.08f, 7.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(3.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(4.55, 0.06f, 6.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(3.35f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(4.75f, -.7f, 7.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(3.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(4.55f, -.35f, 8.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);
#pragma endregion

#pragma region 3rd Row
	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-5.05f, 0.0f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-5.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-4.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-5.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-4.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-5.75f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-4.35f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-5.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-4.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-3.0f, 0.0f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-3.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-2.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-3.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-2.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-3.70f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-2.30f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-3.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-2.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Center Aisle

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(2.0f, 0.0f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(1.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(2.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(1.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(2.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(1.3f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(2.70f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(1.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(2.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(4.05f, 0.0f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(3.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(4.55, 0.08f, 4.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(3.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(4.55, 0.06f, 3.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(3.35f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(4.75f, -.7f, 4.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(3.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(4.55f, -.35f, 5.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);
#pragma endregion

#pragma region 4th Row
	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-5.05f, 0.0f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-5.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-4.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-5.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-4.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-5.75f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-4.35f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-5.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-4.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-3.0f, 0.0f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-3.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-2.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-3.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-2.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-3.70f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-2.30f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-3.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-2.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Center Aisle

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(2.0f, 0.0f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(1.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(2.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(1.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(2.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(1.3f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(2.70f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(1.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(2.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(4.05f, 0.0f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(3.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(4.55, 0.08f, 1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(3.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(4.55, 0.06f, .9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(3.35f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(4.75f, -.7f, 1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(3.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(4.55f, -.35f, 2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);
#pragma endregion

#pragma region Alberto Territory
	//Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-4.00f, 0.0f, -1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Keyboards
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Keyboard.obj", "Keyboard");
	v3Position = vector3(-4.05, 0.08f, -1.2f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Monitors
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Monitor.obj", "Monitor");
	v3Position = vector3(-4.05, 0.06f, -.9f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Computer Towers
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Computer.obj", "Computer");
	v3Position = vector3(-4.75f, -.7f, -1.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);

	//Chairs
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Chair.obj", "Chair");
	v3Position = vector3(-4.05f, -.35f, -2.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(-90.0f), AXIS_Y);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);
#pragma endregion

#pragma region Back Desk
	//Back Desk
	m_pEntityMngr = MyEntityManager::GetInstance();
	m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk");
	v3Position = vector3(-.5f, 0.0f, 13.0f);
	m4Position = glm::translate(v3Position);
	m4Position = m4Position * glm::rotate(glm::radians(90.0f), AXIS_Y);
	m4Position = m4Position * glm::rotate(glm::radians(180.0f), AXIS_X);
	m_pEntityMngr->SetModelMatrix(m4Position);
	m_pEntityMngr->UsePhysicsSolver(false);
#pragma endregion

	//m_pEntityMngr->AddEntity("Stan\\Desk.obj", "Desk2");
	//position = vector3(0.0f, 0.0f, 0.0f);
	//m4Position = glm::translate(position);
	//m_pEntityMngr->SetModelMatrix(m4Position);
	//m_pEntityMngr->UsePhysicsSolver();

	//for (int i = 0; i < 100; i++)
	//{
	//	m_pEntityMngr->AddEntity("Minecraft\\Cube.obj", "Cube_" + std::to_string(i));
	//	vector3 v3Position = vector3(glm::sphericalRand(12.0f));
	//	v3Position.y = 0.0f;
	//	matrix4 m4Position = glm::translate(v3Position);
	//	m_pEntityMngr->SetModelMatrix(m4Position * glm::scale(vector3(1.5f)));
	//	m_pEntityMngr->UsePhysicsSolver(true);
	//	m_pEntityMngr->SetMass(1.5);

	//	//m_pEntityMngr->SetMass(i+1);
	//}
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
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();
	
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
	//release GUI
	ShutdownGUI();
}