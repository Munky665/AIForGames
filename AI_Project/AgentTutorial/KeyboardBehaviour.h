#pragma once
#include "Behaviour.h"
class KeyboardBehaviour :
	public IBehaviour
{
private:
	bool isMoving;
	Vector2 force;
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime, Level currentMap);

};

