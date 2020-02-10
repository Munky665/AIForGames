#include "WanderBehaviour.h"

#include "Agent.h"



WanderBehaviour::WanderBehaviour()
{
}


WanderBehaviour::~WanderBehaviour()
{
}

glm::vec2 WanderBehaviour::Update(Agent* agent, float deltaTime, Level current)
{
	float distance = 0;
	glm::vec2 targetMag(0, 0);
	targetMag = m_targetPos - agent->GetPosition();	
	if (glm::length(distance) < 10)
	{
		m_targetPos = glm::vec2(rand() % 1280 + 100, rand() % 720 + 100);
	}
	else
	{
		glm::vec2 t_agent = agent->GetPosition();
		glm::vec2 force(0, 0);
		glm::vec2 direction = m_targetPos - t_agent;
		glm::normalize(direction);
		direction *= m_speed;
		force = agent->GetVelocity() + direction;
		
		return force;
	}

}

void WanderBehaviour::SetTarget(glm::vec2 target)
{
	m_targetPos = target;
}

void WanderBehaviour::SetSpeed(float speed)
{
	m_speed = speed;
}

void WanderBehaviour::SetAngle(glm::vec2 displacment, float value)
{
	float len = glm::length(displacment);
	displacment.x = cosf(value) * len;
	displacment.y = sinf(value) * len;
}
