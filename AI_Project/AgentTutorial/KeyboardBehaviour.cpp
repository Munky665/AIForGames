#include "KeyboardBehaviour.h"
#include <Input.h>
#include "Agent.h"

KeyboardBehaviour::KeyboardBehaviour()
{
}


KeyboardBehaviour::~KeyboardBehaviour()
{
}

Vector2 KeyboardBehaviour::Update(Agent * agent, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	Vector2 force(0, 0);
	isMoving = false;

	if (input->isKeyDown(aie::INPUT_KEY_UP) || input->isKeyDown(aie::INPUT_KEY_W))
	{
		force.y = 250.0f;
		isMoving = true;
		agent->SetRotation(0);
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) || input->isKeyDown(aie::INPUT_KEY_S))
	{
		force.y = -250.0f;
		isMoving = true;
		agent->SetRotation(3.2);
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A))
	{
		force.x = -250.0f;
		isMoving = true;
		agent->SetRotation(1.5);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D))
	{
		force.x = 250.0f;
		isMoving = true;
		agent->SetRotation(4.7);
	}

	if (isMoving == false)
	{
		agent->SetVelocity(Vector2(0, 0));
		force = Vector2(0, 0);
	}
	return force;
}
