#pragma once
#include "Behaviour.h"
#include "SteeringForce.h"

class SteeringBehaviour :
	public IBehaviour
{
public:
	SteeringBehaviour(SteeringForce* force);
	~SteeringBehaviour();

private:
	SteeringForce* m_force;
};

