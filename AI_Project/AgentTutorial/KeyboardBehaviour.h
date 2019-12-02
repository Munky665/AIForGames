#pragma once
#include "Behaviour.h"
class KeyboardBehaviour :
	public IBehaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime);
};

