#pragma once
#define _USE_MATH_DEFINES
#include <MathLib.h>
#include <cmath>
class Agent;

class IBehaviour
{
public:
	IBehaviour();
	//pure virtual function for executing the behaviour
	virtual Vector2 Update(Agent* ptr, float deltaTime) = 0;
	virtual~IBehaviour();
	
	Vector2 GetOriAsVec(float orientation);
};

