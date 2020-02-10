#pragma once
#include "Behaviour.h"
class KeyboardBehaviour :
	public IBehaviour
{
private:
	bool isMoving;
	glm::vec2 force;
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual glm::vec2 Update(Agent* agent, float deltaTime, Level currentMap);

};

