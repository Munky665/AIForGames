#include "SeekBehaviour.h"
#include "Agent.h"


SeekBehaviour::SeekBehaviour()
{
}


SeekBehaviour::~SeekBehaviour()
{
}

Vector2 SeekBehaviour::Update(Agent * agent, float deltaTime)
{
	if (m_target == nullptr)
	{
		return Vector2(0, 0);
	}
	else
	{
		Vector2 t_agent = agent->GetPosition();
		Vector2 t_target = m_target->GetPosition();
		Vector2 force(0, 0);

		Vector2 direction = t_target - t_agent;
		direction.normalise();
		direction *= m_speed;
		force = direction - agent->GetVelocity();
		return force;
	}
	
}

void SeekBehaviour::SetTarget(Agent * agent)
{
	m_target = agent;
}

void SeekBehaviour::SetSpeed(float speed)
{
	m_speed = speed;
}
