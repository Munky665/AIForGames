#pragma once
#include "Behaviour.h"
class SeekBehaviour :
	public IBehaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();

	virtual glm::vec2 Update(Agent* agent, float deltaTime);
	void SetTarget(Agent* agent);
	void SetSpeed(float speed);

private:
	Agent* m_target;
	float m_speed;
};

