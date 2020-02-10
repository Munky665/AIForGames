#pragma once
#include "Behaviour.h"

class WanderBehaviour :
	public IBehaviour
{
public:
	WanderBehaviour();
	~WanderBehaviour();

	virtual glm::vec2 Update(Agent* agent, float deltaTime, Level current);
	void SetTarget(glm::vec2 target);
	void SetSpeed(float speed);
	void SetAngle(glm::vec2 displacement, float value);

private:
	Agent* m_target;
	glm::vec2 m_targetPos;
	float m_speed;
	float wanderAngle;
};

