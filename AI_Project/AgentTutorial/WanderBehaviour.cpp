#include "WanderBehaviour.h"

#include "Agent.h"



WanderBehaviour::WanderBehaviour()
{
}


WanderBehaviour::~WanderBehaviour()
{
}

Vector2 WanderBehaviour::Update(Agent* agent, float deltaTime)
{
	float distance = 0;
	Vector2 targetMag(0, 0);
	targetMag = m_targetPos - agent->GetPosition();
	distance = targetMag.magnitude();
	if (distance < 10)
	{
		m_targetPos = Vector2(rand() % 1280 + 100, rand() % 720 + 100);
	}
	else
	{
		Vector2 t_agent = agent->GetPosition();
		Vector2 force(0, 0);
		Vector2 direction = m_targetPos - t_agent;
		direction.normalise();
		direction *= m_speed;
		force = agent->GetVelocity() + direction;
		return force;
	}

}

void WanderBehaviour::SetTarget(Vector2 target)
{
	m_targetPos = target;
}

void WanderBehaviour::SetSpeed(float speed)
{
	m_speed = speed;
}

void WanderBehaviour::SetAngle(Vector2 displacment, float value)
{
	float len = displacment.magnitude();
	displacment.x = cosf(value) * len;
	displacment.y = sinf(value) * len;
}
