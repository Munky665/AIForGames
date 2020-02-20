#pragma once
#include "Decision.h"
#include <list>
#include "Node.h"
#include "DNode.h"

class PatrolBehaviour :
	public DNode
{
public:
	PatrolBehaviour(Agent* a, MapLoader* map);
	virtual ~PatrolBehaviour();
	
	virtual void MakeDecision(Agent * a, float deltaTime, MapLoader* map) override;

	const Node& GetCurrentNode();
	void SetNext();
	Node* GetTargetNode();

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
private:
	
	std::list<const Node*>::iterator m_currentNode;
	std::list<const Node*> m_path;

	int lastStopped = 0;
	int target = 0;
	std::vector<Node*> patrolPoints;

	int m_waypoints = 6;

	DNode* m_a;
	DNode* m_b;
	Condition* m_c;

	Node* m_begin;
	Node* m_end;
};

