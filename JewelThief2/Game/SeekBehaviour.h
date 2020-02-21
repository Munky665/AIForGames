#pragma once
#include "Decision.h"
#include <list>
#include "Node.h"
#include "DNode.h"

class Player;

class SeekBehaviour :
	public DNode
{
public:
	SeekBehaviour(Player* p, MapLoader* map);
	virtual ~SeekBehaviour();

	virtual void MakeDecision(Agent * a, float deltaTime, MapLoader* map) override;

	Node& GetCurrentNode();
	Node* GetTargetNode();

	int FindTarget(MapLoader * map);

	void SetCurrentNode(Node* n);

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

	std::list< Node*>::iterator m_currentNode;
	std::list< Node*> m_path;

	int m_lastStopped = 0;
	int m_target = 0;

	DNode* m_a;
	DNode* m_b;
	Condition* m_c;

	Player* m_player;

	Node* m_targetNode;

	Node* m_begin;
	Node* m_end;

};

