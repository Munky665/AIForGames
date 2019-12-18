#include "Agent.h"
#include "Behaviour.h"
#include <Texture.h>

Agent::Agent(Vector2 pos, Vector2 vel, float maxVel, float maxForce)
{
	m_Position = pos;
	m_Velocity = vel;
	m_MaxVelocity = maxVel;
	m_MaxForce = maxForce;
}

Agent::Agent(Vector2 pos)
{
	m_Position = pos;
}


Agent::~Agent()
{
}

void Agent::Update(float deltaTime)
{
	m_Force = Vector2(0,0);

	for(auto b : m_BehaviourList)
	{
		if (b->Update(this, deltaTime) != Vector2(0, 0)) {
			m_Force += b->Update(this, deltaTime);
		}
		else
		{
			m_Force = Vector2(0, 0);
			m_Velocity = Vector2(0, 0);
		}
	}
	//clamp
	if (m_Force.magnitude() > m_MaxForce)
	{
		m_Force = m_Force.normalise(m_Force) * m_MaxForce;
	}

	m_Velocity += m_Force * deltaTime;

	if (m_Velocity.magnitude() > m_MaxVelocity)
	{
		m_Velocity = m_Velocity.normalise(m_Velocity) * m_MaxVelocity;
	}

	m_Position += m_Velocity * deltaTime;
}

void Agent::SetPosition(Vector2 position)
{
	m_Position = position;
}

Vector2 Agent::GetPosition()
{
	return m_Position;
}

void Agent::SetVelocity(Vector2 velocity)
{
	m_Velocity = velocity;
}

Vector2 Agent::GetVelocity()
{
	return m_Velocity;
}

Vector2 Agent::GetForce()
{
	return m_Force;
}



void Agent::AddForce(Vector2 force, float deltaTime)
{
	if (m_Velocity.magnitude() < m_MaxVelocity)
	{
		m_Velocity += force * deltaTime;
	}
}

void Agent::SetSprite(const char * string)
{
	sprite = new aie::Texture(string);
}

void Agent::SetRotation(float num)
{
	m_Rotation = num;
}

void Agent::Draw(aie::Renderer2D* renderer)
{
	renderer->drawSprite(sprite, m_Position.x, m_Position.y, 40, 40, m_Rotation);
}

void Agent::AddBehaviour(IBehaviour* behaviour)
{
	m_BehaviourList.push_back(behaviour);
}