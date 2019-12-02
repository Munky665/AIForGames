#pragma once
#include "Behaviour.h"
class WanderingBehaviour :
	public IBehaviour
{
public:
	WanderingBehaviour();
	virtual ~WanderingBehaviour();

private:
	float offset;
	float radius;
	float rate;
};

