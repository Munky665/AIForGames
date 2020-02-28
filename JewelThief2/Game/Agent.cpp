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

Agent::Agent(int room, MapLoader* map, Player* p)
{
	m_roomNumber = room;
	SetSprite();
	SetPosition(map->GetRoom(m_roomNumber)->GetNodeMap()[110]->position);
	for (int i = 0; i < 4; ++i)
	{
		m_searchBoxes.push_back(new SearchBox(m_position, 30.0f));
	}
	//create nodes on tree
	m_patrol = new PatrolBehaviour(this, map);
	m_search = new SearchBehaviour(p);
	m_seek = new SeekBehaviour(p, map);
	//set nodes on tree
	
	m_search->SetNodeA(nullptr);
	m_search->SetNodeB(m_seek);
	
	m_patrol->SetNodeA(m_seek); //true
	m_patrol->SetNodeB(m_search); //false

	m_seek->SetNodeA(nullptr);
	m_seek->SetNodeB(nullptr);

	m_target = m_patrol->GetTargetNode();
	//set  conditions
	m_patrol->SetCondition(new CheckRange(m_target, 1.0f));
	m_seek->SetCondition(new Chase(p));
	m_search->SetCondition(new UseSearch());


	m_searchTimer = 0;

}

Agent::~Agent()
{
}

void Agent::Update(float dT, MapLoader* map, Player* p)
{
	//checks if agent exists in current room
	if (map->GetCurrentRoom()->GetRoomId() == m_roomNumber) {
		
		if (glm::length(p->GetPosition() - m_position) < 100)
		{
			m_chase = true;
		}
		m_patrol->MakeDecision(this, dT, map);

		for (SearchBox* b : m_searchBoxes)
		{
			if (m_searchTimer >= 0) {
				if (!m_pathEnd)
					b->SetPosition(m_position);
				if (m_chase)
				{
					b->SetPosition(m_position);
				}
			}
		}

		if (m_pathEnd)
		{
			m_searchTimer += 1 * dT;
			//reset to next node then patrol
			if (m_searchTimer > 4)
			{
				m_patrol->SetNext();
				m_pathEnd = false;
				m_searchTimer = 0;
				m_target = m_patrol->GetTargetNode();
			}
		}
		//if chasing keep patrol current node current
		if (m_chase == true)
		{
			m_patrol->SetCurrentNode(&m_seek->GetCurrentNode());
		}
		//if patroling keep chase current node current
		else if (m_chase == false)
		{
			m_seek->SetCurrentNode(&m_patrol->GetCurrentNode());
		}
	}
	//reset chase if this does not exist in current room
	else
		m_chase = false;
}

void Agent::Draw(aie::Renderer2D * r)
{
	for (SearchBox* b : m_searchBoxes)
	{
		b->Draw(r);
	}
	if (m_chase != true) {
		r->drawSprite(m_sprite, m_position.x, m_position.y, 0, 0);
	}
	else
	{
		r->setRenderColour(1, 0, 0, 1);
		r->drawSprite(m_sprite, m_position.x, m_position.y, 0, 0);
		r->setRenderColour(1, 1, 1, 1);
	}
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


Node * Agent::GetTarget()
{
	return m_target;
}

std::vector<SearchBox*>& Agent::GetSearchBoxes()
{
	return m_searchBoxes;
}

float Agent::GetSearchTime()
{
	return m_searchTimer;
}

bool Agent::GetPathEnd()
{
	return m_pathEnd;
}

bool Agent::GetChase()
{
	return m_chase;
}

const Node* Agent::GetCurrentNode()
{
	return m_currentNode;
}

void Agent::SetPosition(glm::vec2 p)
{
	m_position = p;
}

void Agent::SetSprite()
{
	m_sprite = new aie::Texture("../bin/Sprites/Agent.png");
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

void Agent::SetChase(bool c)
{
	m_chase = c;
}
