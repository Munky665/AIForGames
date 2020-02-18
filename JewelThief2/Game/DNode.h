#pragma once
#include "Decision.h"
#include "Condition.h"

class DNode : Decision
{
	DNode* m_a;
	DNode* m_b;
	Condition* m_c;
public:

	virtual void MakeDecision(Agent * agent, float dT, MapLoader * map) override
	{
		if (m_c->Test(agent))
			m_a->MakeDecision(agent, dT, map);
		else
			m_b->MakeDecision(agent, dT, map);
	}

	virtual void SetNodeA(DNode* a)
	{
		m_a = a;
	}

	virtual void SetNodeB(DNode* b)
	{
		m_b = b;
	}

	virtual void SetCondition(Condition* c)
	{
		m_c = c;
	}

};