#include "Agent.h"
#include "Behaviour.h"
#include <Texture.h>
#include "Collider.h"
#include "Rect.h"

Agent::Agent(Vector2 pos, Vector2 vel, float maxVel, float maxForce, int currentX, int currentY)
{
	m_Position = pos + 10;
	m_Velocity = vel;
	m_MaxVelocity = maxVel;
	m_MaxForce = maxForce;
	m_CurrentX = currentX;
	m_CurrentY = currentY;
	m_collider = new Rect(pos.x , pos.y, 32, 32);
}

Agent::Agent(Vector2 pos)
{
	m_Position = pos;
}


Agent::~Agent()
{
}

void Agent::Update(float deltaTime, Level currentMap)
{
	m_collider->x = m_Position.x;
	m_collider->y = m_Position.y;
	Vector2 m_Force(0, 0);

	for (auto b : m_BehaviourList)
	{		
		m_Force = b->Update(this, deltaTime, currentMap);
	}

	if (m_Force.x == 0 && m_Force.y == 0) {
		m_Velocity -= m_Velocity;
	}
	else {
		m_Velocity += m_Force * deltaTime;
	}

	//clamp
	if (m_Force.magnitude() > m_MaxForce)
	{
		m_Force = m_Force.normalise(m_Force) * m_MaxForce;
	}
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




void Agent::AddForce(Vector2 force, float deltaTime)
{
	if (m_Velocity.magnitude() < m_MaxVelocity)
	{
		m_Velocity += force * deltaTime;
	}
}

void Agent::SetSprite(const char * string)
{
	if(string != "")
	sprite = new aie::Texture(string);
	else
	{
		sprite = nullptr;
	}
}

void Agent::SetRotation(float num)
{
	m_Rotation = num;
}

Vector2 Agent::CurrentTile()
{
	return Vector2(m_CurrentX, m_CurrentY);
}

void Agent::SetCurrentTile(int x, int y)
{
	m_CurrentX = x;
	m_CurrentY = y;
}

void Agent::Draw(aie::Renderer2D* renderer)
{
	if (this->sprite != nullptr)
		renderer->drawSprite(sprite, m_Position.x, m_Position.y, 32, 32, m_Rotation);
	else
		renderer->drawBox(m_Position.x, m_Position.y, 32, 32);
}

void Agent::AddBehaviour(IBehaviour* behaviour)
{
	m_BehaviourList.push_back(behaviour);
}

Rect* Agent::GetCollider()
{
	return m_collider;
}