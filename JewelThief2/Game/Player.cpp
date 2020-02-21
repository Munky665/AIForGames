#include "Player.h"
#include <Texture.h>
#include "Rect.h"
#include "MapLoader.h"




Player::Player(glm::vec2 p, float s, const char* sprite)
{
	m_position = p;
	m_speed= s;
	SetSprite(sprite);
	m_collider = new Rect(p.x, p.y, 54, 54);
}


Player::~Player()
{
}

void Player::Update(float dT, MapLoader* map)
{
	//make sure collider is in the same position as player
	colliderUpdate();

	//run updates from behaviour list
	for (IBehaviour* b : m_behaviourList)
	{
		b->Update(this, dT, map);
	}


}

void Player::Draw(aie::Renderer2D * r)
{
		r->drawSprite(m_sprite, m_position.x, m_position.y, 0,0,m_rotation);
}

void Player::AddBehaviour(IBehaviour * b)
{
	m_behaviourList.push_back(b);
}

void Player::colliderUpdate()
{
	m_collider->x = m_position.x;
	m_collider->y = m_position.y;
}

glm::vec2 Player::GetPosition()
{
	return m_position;
}

float Player::GetSpeed()
{
	return m_speed;
}

Rect * Player::GetCollider()
{
	return m_collider;
}

void Player::SetPosition(glm::vec2 p)
{
	m_position = p;
}

void Player::SetVelocity(glm::vec2 p)
{
	m_position += p;
}

void Player::SetSprite(const char* sprite)
{
	if (sprite != "")
		m_sprite = new aie::Texture(sprite);
	else
		throw std::runtime_error("No Player Sprite Located");
}

void Player::SetRotation(float r)
{
	m_rotation = r;
}
