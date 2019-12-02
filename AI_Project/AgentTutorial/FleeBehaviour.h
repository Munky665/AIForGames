#pragma once
#include "Behaviour.h"
class FleeBehaviour :
	public IBehaviour
{
public:
	FleeBehaviour();
	virtual ~FleeBehaviour();

	virtual Vector2 Update(Agent* agent, float deltaTime);
	void SetTarget(Agent* agent);
	void SetSpeed(float speed);

private:
	Agent* m_target;
	float m_speed;
};

