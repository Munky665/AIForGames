#include "KeybaordBehaviour.h"
#include <Input.h>
#include <glm/glm.hpp>
#include "Player.h"
#include "Collider.h"
#include "Tile.h"
#include "MapLoader.h"
#include "Room.h"

int ColliderCheck(glm::vec2 force, Player* p, MapLoader* map)
{
	for (int i = 0; i < 21 * 12; ++i)
	{
		if (map->GetCurrentRoom()->GetTile(i)->IsWalkable() == false)
		{
			if (CheckCollision(p->GetCollider(), map->GetCurrentRoom()->GetTile(i)->GetCollider(), force))
				if(	map->GetCurrentRoom()->GetTile(i)->IsDoor() == false)
					return true;
		}
	}
	return false;
}


KeybaordBehaviour::KeybaordBehaviour()
{
}


KeybaordBehaviour::~KeybaordBehaviour()
{
}

bool KeybaordBehaviour::Update(Agent * a, float dT)
{
	return false;
}

void KeybaordBehaviour::Update(Player * p, float dT, MapLoader* map)
{

	aie::Input* input = aie::Input::getInstance();
	glm::vec2 force(0, 0);


	if (input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W))
	{
		
		force = glm::normalize(glm::vec2(0, 250) ) * p->GetSpeed() * dT;
		if (ColliderCheck(force, p, map) )
		{
			force *= -force;
		}

		p->SetVelocity(force);
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_S))
	{

		force = glm::normalize(glm::vec2(0, -250)) * p->GetSpeed() * dT;
		if (ColliderCheck(force, p, map) )
		{
			force *= force;
		}
		
		p->SetVelocity(force);

	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A))
	{
		force = glm::normalize(glm::vec2(-250, 0)) * p->GetSpeed()* dT;
		if (ColliderCheck(force, p, map) )
		{
				force *= force;
		}
		
		p->SetVelocity(force);
		p->SetRotation(0);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D))
	{
		force = glm::normalize(glm::vec2(250, 0)) * p->GetSpeed() * dT;
		if (ColliderCheck(force, p, map))
		{
				force *= -force;
		}
		p->SetVelocity(force);
		p->SetRotation(1);
	}

}



