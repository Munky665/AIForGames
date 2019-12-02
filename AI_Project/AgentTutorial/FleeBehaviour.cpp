#include "FleeBehaviour.h"
#include "Agent.h"


FleeBehaviour::FleeBehaviour()
{
}


FleeBehaviour::~FleeBehaviour()
{
}

Vector2 FleeBehaviour::Update(Agent * agent, float deltaTime)
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

		Vector2 direction = t_agent - t_target;
		direction.normalise();
		direction *= m_speed;
		direction =  direction - agent->GetVelocity();
		return direction;
	}

}

void FleeBehaviour::SetTarget(Agent * agent)
{
	m_target = agent;
}

void FleeBehaviour::SetSpeed(float speed)
{
	m_speed = speed;
}