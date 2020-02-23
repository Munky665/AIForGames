#pragma once
#include "DNode.h"
#include <vector>

class SearchBox;

class SearchBehaviour :
	public DNode
{
	DNode* m_a;
	DNode* m_b;
	Condition* m_c;
public:
	SearchBehaviour( Player* p);
	virtual ~SearchBehaviour();

	virtual void MakeDecision(Agent * a, float deltaTime, MapLoader* map) override;

	virtual void SetNodeA(DNode* a) override
	{
		m_a = a;
	}

	virtual void SetNodeB(DNode* b) override
	{
		m_b = b;
	}

	virtual void SetCondition(Condition* c) override
	{
		m_c = c;
	}

	DNode* m_patrolRef;
	Player* m_player;
	float m_speed = 100;
};

