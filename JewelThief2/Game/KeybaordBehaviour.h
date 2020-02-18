#pragma once
#include "IBehaviour.h"
class KeybaordBehaviour :
	public IBehaviour
{
public:
	KeybaordBehaviour();
	virtual ~KeybaordBehaviour();

	virtual bool Update(Agent* a, float dT) override;
	virtual void Update(Player* p, float dT, MapLoader* map) override;
};

