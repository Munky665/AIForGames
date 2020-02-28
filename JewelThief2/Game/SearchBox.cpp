#include "SearchBox.h"
#include "Rect.h"
#include "collider.h"
#include "Player.h"

SearchBox::SearchBox(glm::vec2 p, float s)
{
	m_size = s;
	m_position = p;
	m_collider = new Rect(p.x, p.y, m_size, m_size);
}


SearchBox::~SearchBox()
{
}

void SearchBox::Update(Player* p)
{
	if (CheckCollision(m_collider, p->GetCollider(), m_velocity))
	{
		m_velocity = glm::vec2(0, 0);
		m_collided = true;
	}
	else 
	{
		m_position += m_velocity;
		m_alpha = 0.5f;
	}
	
	m_collider->x = m_position.x;
	m_collider->y = m_position.y;
}

glm::vec2 SearchBox::GetPosition()
{
	return glm::vec2();
}

bool SearchBox::HasCollided()
{
	return m_collided;
}

void SearchBox::SetPosition(glm::vec2 p)
{
	m_position = p;
	m_alpha = 0;
}

void SearchBox::SetVeloity(glm::vec2 pos, Player* p)
{
	m_velocity = pos;
	Update(p);
}

void SearchBox::Draw(aie::Renderer2D* r)
{
	r->setRenderColour(1, 0, 0, m_alpha);
	r->drawCircle(m_position.x, m_position.y, m_size);
	r->setRenderColour(1, 1, 1, 1);
	
	//reset collision is here so that it is done after everything else
	m_collided = false;
}
