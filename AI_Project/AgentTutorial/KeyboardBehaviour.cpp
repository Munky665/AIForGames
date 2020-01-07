#include "KeyboardBehaviour.h"
#include <Input.h>
#include "Agent.h"
#include "Collider.h"

KeyboardBehaviour::KeyboardBehaviour()
{
}


KeyboardBehaviour::~KeyboardBehaviour()
{
}

Vector2 KeyboardBehaviour::Update(Agent * agent, float deltaTime, Level currentMap)
{
	aie::Input* input = aie::Input::getInstance();
	Vector2 force(0, 0);

	if (input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W))
	{
			force.y += 250;
			agent->SetRotation(0);
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_S))
	{
		
			force.y -= 250;
			agent->SetRotation(3.2);

	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A))
	{
			force.x -= 250;
			agent->SetRotation(1.5);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D))
	{
			force.x += 250;
			agent->SetRotation(4.7);
	}

	for (int x = 0; x < 36; x++) {
		for (int y = 0; y < 36; y++) {
			if (currentMap.GetTile(x, y)->IsWalkable() == false) {
				if (Collider::CheckCollision(agent->GetCollider(), currentMap.GetTile(x, y)->collider, force) == 1)
				{
					force -= force;
				}
			}
		}
	}

	return force;
}
