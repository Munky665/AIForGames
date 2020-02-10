#include "Agent.h"
#include "Behaviour.h"
#include <Texture.h>
#include "Collider.h"
#include "Rect.h"
#include <iostream>

Agent::Agent(glm::vec2 pos, float maxVel, float maxForce)
{
	m_Position = pos;
	m_MaxVelocity = maxVel;
	m_MaxForce = maxForce;
	m_collider = new Rect(pos.x , pos.y, 32, 32);
}

Agent::Agent(glm::vec2 pos)
{
	m_Position = pos;
}


Agent::~Agent()
{
}

void Agent::Update(float deltaTime, std::vector<Node> node)
{
	m_collider->x = m_Position.x;
	m_collider->y = m_Position.y;

	glm::vec2 m_Force(0, 0);

	for (auto b : m_BehaviourList)
	{
		m_Force = b->Update(this, deltaTime, node);
	}
	std::cout << m_Force.x << " " << m_Force.y << "  Force" << std::endl;
	//glm::normalize(m_Force);
}

void Agent::SetPosition(glm::vec2 position)
{
	m_Position = position;
}

glm::vec2 Agent::GetPosition() const
{
	return m_Position;
}

void Agent::SetVelocity(glm::vec2 velocity)
{
	m_Velocity = velocity;
}

glm::vec2 Agent::GetVelocity()
{
	return m_Velocity;
}




void Agent::AddForce(glm::vec2 force, float deltaTime)
{
	if (glm::length(m_Velocity) < m_MaxVelocity)
	{
		m_Velocity += force * deltaTime;
	}
}

void Agent::SetSprite(const char * string)
{
	if(string != "")
	m_sprite = new aie::Texture(string);
	else
	{
		m_sprite = nullptr;
	}
}

void Agent::SetRotation(float num)
{
	m_Rotation = num;
}

glm::vec2 Agent::CurrentTile()
{
	return glm::vec2(m_CurrentX, m_CurrentY);
}

void Agent::SetCurrentTile(int x, int y)
{
	m_CurrentX = x;
	m_CurrentY = y;
}

void Agent::Draw(aie::Renderer2D* renderer)
{
	if (this->m_sprite != nullptr)
		renderer->drawSprite(m_sprite, m_Position.x, m_Position.y, 32, 32, m_Rotation);
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