#pragma once
#define _USE_MATH_DEFINES
#include <MathLib.h>
#include <cmath>
class Agent;
class Level;
class IBehaviour
{
public:
	IBehaviour();
	//pure virtual function for executing the behaviour
	virtual Vector2 Update(Agent* ptr, float deltaTime, Level currentMap) = 0;
	virtual~IBehaviour();
	
};

