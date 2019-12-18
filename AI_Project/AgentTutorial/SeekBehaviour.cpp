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
		//get this agents position
		Vector2 t_agent = agent->GetPosition();
		//get targets position
		Vector2 t_target = m_target->GetPosition();
		//create force vector
		Vector2 force(0, 0);
		//create direction vector
		Vector2 direction = t_target - t_agent;
		//normalise the direction vector
		direction.normalise();
		//multiply direction by speed
		direction *= m_speed;
		//add direction - velocity to force
		force = direction - agent->GetVelocity();
		//return force to agent
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
