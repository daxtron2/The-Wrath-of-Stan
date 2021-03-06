#include "MySolver.h"
using namespace Simplex;
//  MySolver
void MySolver::Init(void)
{
	m_v3Acceleration = ZERO_V3;
	m_v3Position = ZERO_V3;
	m_qOrientation = quaternion();
	m_v3Velocity = ZERO_V3;
	m_fMass = 1.0f;
	m_bIsCollding = false;
}
void MySolver::Swap(MySolver& other)
{
	std::swap(m_v3Acceleration, other.m_v3Acceleration);
	std::swap(m_v3Velocity, other.m_v3Velocity);
	std::swap(m_v3Position, other.m_v3Position);
	std::swap(m_fMass, other.m_fMass);
}
void MySolver::Release(void) {/*nothing to deallocate*/ }
//The big 3
MySolver::MySolver(void) { Init(); }
MySolver::MySolver(MySolver const& other)
{
	m_v3Acceleration = other.m_v3Acceleration;
	m_v3Velocity = other.m_v3Velocity;
	m_v3Position = other.m_v3Position;
	m_fMass = other.m_fMass;
}
MySolver& MySolver::operator=(MySolver const& other)
{
	if (this != &other)
	{
		Release();
		Init();
		MySolver temp(other);
		Swap(temp);
	}
	return *this;
}
MySolver::~MySolver() { Release(); }

//Accessors
void MySolver::SetPosition(vector3 a_v3Position) { m_v3Position = a_v3Position; }
vector3 MySolver::GetPosition(void) { return m_v3Position; }

void MySolver::SetOrientation(quaternion a_qOrientation) { m_qOrientation = a_qOrientation; }
quaternion MySolver::GetOrientation(void) { return m_qOrientation; }

void MySolver::SetSize(vector3 a_v3Size) { m_v3Size = a_v3Size; }
vector3 MySolver::GetSize(void) { return m_v3Size; }

void MySolver::SetVelocity(vector3 a_v3Velocity) { m_v3Velocity = a_v3Velocity; }
vector3 MySolver::GetVelocity(void) { return m_v3Velocity; }

void MySolver::SetMass(float a_fMass) { m_fMass = a_fMass; }
float MySolver::GetMass(void) { return m_fMass; }

void MySolver::SetRigidbody(MyRigidBody* a_pRigidbody) { m_pRigidbody = a_pRigidbody; }
MyRigidBody* MySolver::GetRigidBody(void) { return m_pRigidbody; }

void MySolver::SetDesk(MyRigidBody* a_pDesk) {
	m_pDesk = a_pDesk;
}

//Methods
void MySolver::ApplyFriction(float a_fFriction)
{
	if (a_fFriction < 0.01f)
		a_fFriction = 0.01f;

	//there is no friction falling
	vector3 v3Negated = vector3(m_v3Velocity.x, 0.0f, m_v3Velocity.z) * (-a_fFriction);
	m_v3Velocity += v3Negated;
	//m_v3Velocity *= 1.0f - a_fFriction;

	//if velocity is really small make it zero
	if (glm::length(m_v3Velocity) < 0.01f)
		m_v3Velocity = ZERO_V3;
}
void MySolver::ApplyForce(vector3 a_v3Force)
{
	m_bGravityApplied = true;
	//check minimum mass
	if (m_fMass < 0.01f)
		m_fMass = 0.01f;
	//f = m * a -> a = f / m

	m_v3Acceleration += a_v3Force / m_fMass;
}
vector3 CalculateMaxVelocity(vector3 a_v3Velocity, float maxVelocity)
{
	if (glm::length(a_v3Velocity) > maxVelocity)
	{
		a_v3Velocity = glm::normalize(a_v3Velocity);
		a_v3Velocity *= maxVelocity;
	}
	return a_v3Velocity;
}
vector3 RoundSmallVelocity(vector3 a_v3Velocity, float minVelocity = 0.01f)
{
	if (glm::length(a_v3Velocity) < minVelocity)
	{
		a_v3Velocity = ZERO_V3;
	}
	return a_v3Velocity;
}

void MySolver::SetIsColliding(bool a_bIsCollding) { m_bIsCollding = a_bIsCollding; }
void MySolver::Update(void)
{

	if (m_pDesk == nullptr)
		ApplyForce(vector3(0.0f, -0.12f, 0.0f) * m_fMass * .5f);

	m_v3Velocity += m_v3Acceleration; //* .0016f;

	float fMaxVelocity = 5.0f;
	m_v3Velocity = CalculateMaxVelocity(m_v3Velocity, fMaxVelocity);

	ApplyFriction(0.1f);
	m_v3Velocity = RoundSmallVelocity(m_v3Velocity, 0.028f);

	if (m_bIsCollding && m_v3Velocity.y < 0.0f)
		m_v3Velocity.y = 0.0f;

	m_v3Position += m_v3Velocity;

	if (m_v3Position.y <= 0)
	{
		m_v3Position.y = 0;
		m_v3Velocity.y = 0;
	}

	m_v3Acceleration = ZERO_V3;

	//m_bCanFall = true;
	//m_bIsCollding = false;

	

	if (m_pDesk != nullptr) {
		if (m_pDesk->GetMinGlobal().x > this->m_pRigidbody->GetMaxGlobal().x || m_pDesk->GetMaxGlobal().x < this->GetRigidBody()->GetMinGlobal().x) {
			m_pDesk = nullptr;
			return;
		}
		if (m_pDesk->GetMinGlobal().z > this->m_pRigidbody->GetMaxGlobal().z || m_pDesk->GetMaxGlobal().z < this->GetRigidBody()->GetMinGlobal().z) {
			m_pDesk = nullptr;
			return;
		}
	}
}
void MySolver::ResolveCollision(MySolver* a_pOther)
{
	float fMagThis = glm::length(m_v3Velocity);
	float fMagOther = glm::length(a_pOther->m_v3Velocity);

	if (this->GetMass() > 12344.f || a_pOther->GetMass() > 12344.f)
	{
		if (this->GetMass() > 15000.f || a_pOther->GetMass() > 15000.f)
		{
			return;
		}
		else
		{
			if (this->GetMass() > 12344.f && a_pOther->GetMass() < 12344.f)
			{
				//a_pOther->ApplyForce(glm::normalize(-a_pOther->GetVelocity()));
				//a_pOther->SetVelocity(-a_pOther->GetVelocity());				
				a_pOther->SetVelocity(glm::normalize(-a_pOther->GetPosition()) * glm::length(a_pOther->GetVelocity()));
			}
			else if (this->GetMass() > 12344.f && a_pOther->GetMass() > 12344.f)
			{
				return;
			}
		}
	}

	//If the forces are large apply them on each other
	if (fMagThis > REPULSIONFORCE || fMagOther > REPULSIONFORCE)
	{
		ApplyForce(-m_v3Velocity);
		a_pOther->ApplyForce(m_v3Velocity);
	}
	else
	{
		vector3 v3Direction = m_v3Position - a_pOther->m_v3Position;
		if (glm::length(v3Direction) != 0)
			v3Direction = glm::normalize(v3Direction);
		v3Direction *= 0.016f; //should be multiplied by the delta time

		ApplyForce(v3Direction);
		a_pOther->ApplyForce(-v3Direction);

		//SetVelocity(ZERO_V3);
		//a_pOther->SetVelocity(ZERO_V3);

		//a_pOther->SetVelocity(m_v3Velocity);
		//SetVelocity(ZERO_V3);
		//m_v3Acceleration = ZERO_V3;

	}
}