#pragma once
#include <list>
#include "IBehaviour.h"
class Agent;


class Decision
{
public:
	virtual void MakeDecision(Agent* a, float dT, MapLoader* map) = 0;
};