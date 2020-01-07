#pragma once
#include "Behaviour.h"

class WanderBehaviour :
	public IBehaviour
{
public:
	WanderBehaviour();
	~WanderBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime, Level current);
	void SetTarget(Vector2 target);
	void SetSpeed(float speed);
	void SetAngle(Vector2 displacement, float value);

private:
	Agent* m_target;
	Vector2 m_targetPos;
	float m_speed;
	float wanderAngle;
};

