#include "Agent.h"
#include "IBehaviour.h"
#include <Texture.h>
#include "SeekBehaviour.h"
#include "SearchBehaviour.h"
#include "PatrolBehaviour.h"
#include "MapLoader.h"
#include "Room.h"
#include "SearchBox.h"
#include "Player.h"

Agent::Agent(RoomId id, MapLoader* map, Player* p)
{
	m_roomNumber = id;
	SetSprite();
	SetPosition(glm::vec2(500, 200));
	for (int i = 0; i < 4; ++i)
	{
		m_searchBoxes.push_back(new SearchBox(m_position, 32.0f));
	}
	//create nodes on tree
	m_decisionTree = new DNode();
	m_patrol = new PatrolBehaviour(this, map);
	m_search = new SearchBehaviour(m_patrol, p);
	//set nodes on tree
	m_decisionTree->SetNodeA(m_patrol);
	m_decisionTree->SetNodeB(m_search);
	
	m_search->SetNodeA(m_search);
	m_search->SetNodeB(m_decisionTree);
	
	m_patrol->SetNodeA(nullptr);
	m_patrol->SetNodeB(nullptr);

	m_currentNode = &m_patrol->GetCurrentNode();
	m_target = m_patrol->GetTargetNode();
	//set  conditions
	m_decisionTree->SetCondition(new CheckRange(m_target, 1.0f));
	m_search->SetCondition(new UseSearch());

	m_searchTimer = 0;

}

Agent::~Agent()
{
}

void Agent::Update(float dT, MapLoader* map)
{

	m_decisionTree->MakeDecision(this, dT, map);
	
	SetRotation(dT);
	for (SearchBox* b : m_searchBoxes)
	{
		if(!m_pathEnd)
			b->SetPosition(m_position);
			
	}
	if (m_pathEnd)
	{
		m_searchTimer = m_searchTimer + 1 * dT;
		if (m_searchTimer > 4)
		{
			m_patrol->SetNext();
			m_pathEnd = false;
			m_searchTimer = 0;
			m_target = m_patrol->GetTargetNode();
		}
	}
}

void Agent::Draw(aie::Renderer2D * r)
{
	for (SearchBox* b : m_searchBoxes)
	{
		b->Draw(r);
	}
	r->drawSprite(m_sprite, m_position.x, m_position.y, 0, 0, m_rotation);
}



void Agent::colliderUpdate()
{
}

glm::vec2 Agent::GetPosition()
{
	return m_position;
}

float Agent::GetSpeed()
{
	return m_speed;
}

int Agent::GetRoomNumber()
{
	return m_roomNumber;
}

DNode* Agent::GetNodeTree()
{
	return m_decisionTree;
}

Node * Agent::GetTarget()
{
	return m_target;
}

std::vector<SearchBox*> Agent::GetSearchBoxes()
{
	return m_searchBoxes;
}

int Agent::GetSearchTime()
{
	return m_searchTimer;
}

bool Agent::GetPathEnd()
{
	return m_pathEnd;
}

void Agent::SetPosition(glm::vec2 p)
{
	m_position = p;
}

void Agent::SetSprite()
{
	m_sprite = new aie::Texture("../bin/Sprites/Agent.png");
}

void Agent::SetRotation(float r)
{
	m_rotation += 0.5 * r;
}

void Agent::SetVelocity(glm::vec2 v)
{
		m_velocity = v;
		m_position += m_velocity;
}

void Agent::setCurrentNode(std::list<const Node *>::iterator n)
{
	m_currentNode = (*n);
}

void Agent::AtPathEnd(bool p)
{
	m_pathEnd = p;
}
