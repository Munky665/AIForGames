#include "FleeBehaviour.h"
#include "Agent.h"


FleeBehaviour::FleeBehaviour()
{
}


FleeBehaviour::~FleeBehaviour()
{
}

glm::vec2 FleeBehaviour::Update(Agent * agent, float deltaTime)
{
	if (m_target == nullptr)
	{
		return glm::vec2(0, 0);
	}
	else
	{
		glm::vec2 t_agent = agent->GetPosition();
		glm::vec2 t_target = m_target->GetPosition();
		glm::vec2 force(0, 0);

		glm::vec2 direction = t_agent - t_target;
		glm::normalize(direction);
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