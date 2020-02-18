#pragma once
#include "IBehaviour.h"
class SeekBehaviour :
	public IBehaviour
{
public:
	SeekBehaviour();
	virtual ~SeekBehaviour();

	// Inherited via IBehaviour
	virtual void Update(Player * p, float deltaTime, MapLoader * map) override;
	virtual bool Update(Agent * a, float deltaTime) override;
};

