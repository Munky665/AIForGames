#include "KeyboardBehaviour.h"
#include <Input.h>


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

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		force.y = 50.0f;
	else if (input->wasKeyReleased(aie::INPUT_KEY_UP))
		force.y = -50.0f;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		force.y = -50.0f;
	else if (input->wasKeyReleased(aie::INPUT_KEY_DOWN))
		force.y = 50.0f;
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		force.x = -50.0f;
	else if (input->wasKeyReleased(aie::INPUT_KEY_LEFT))
		force.x = 50.0f;
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		force.x = 50.0f;
	else if (input->wasKeyReleased(aie::INPUT_KEY_RIGHT))
		force.x = -50.0f;
	return force;
}
