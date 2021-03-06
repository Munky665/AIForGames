#include "Agent.h"
#include "IBehaviour.h"
#include <Texture.h>
#include "SeekBehaviour.h"
#include "SearchBehaviour.h"
#include "PatrolBehaviour.h"
#include "MapLoader.h"
#include "Room.h"
#include "SearchBox.h"
#include "Collider.h"
#include "Player.h"

Agent::Agent(int room, MapLoader* map, Player* p)
{
	m_roomNumber = room;
	SetSprite();
	SetPosition(map->GetRoom(m_roomNumber)->GetNodeMap()[137]->position);
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

	m_collider = new Rect(m_position.x, m_position.y, 50, 50);
	m_searchTimer = 0;

}

Agent::~Agent()
{
}

void Agent::Update(float dT, MapLoader* map, Player* p)
{
	m_currentRoom = map->GetCurrentRoom()->GetRoomId();
	//checks if agent exists in current room
	if (m_currentRoom == m_roomNumber) {

		if (glm::length(p->GetPosition() - m_position) < 100)
		{
			m_chase = true;
			if (CheckCollision(p->GetCollider(), m_collider, m_velocity))
			{
				m_captured = true;
			}
		}
		//start of decision making
		m_patrol->MakeDecision(this, dT, map);

		//keeps search boxes with agent unless searching
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
	{
		m_chase = false;
	}
	colliderUpdate();
}

//draw the agent and search boxes
void Agent::Draw(aie::Renderer2D * r)
{
	if (m_currentRoom == m_roomNumber)
	{
		for (SearchBox* b : m_searchBoxes)
		{
			if (b != nullptr)
			{
				b->Draw(r);
			}
			else
			{
				std::runtime_error("Search boxes do not exist");
			}
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
}


//updates the collider position
void Agent::colliderUpdate()
{
	m_collider->x = m_position.x;
	m_collider->y = m_position.y;
}
//returns agent postion
glm::vec2 Agent::GetPosition()
{
	return m_position;
}
//returns speed variable
float Agent::GetSpeed()
{
	return m_speed;
}
//returns the room number agent operates in
int Agent::GetRoomNumber()
{
	return m_roomNumber;
}

//gets agents target node
Node * Agent::GetTarget()
{
	return m_target;
}
//returns the vector array of search boxes
std::vector<SearchBox*>& Agent::GetSearchBoxes()
{
	return m_searchBoxes;
}
//returns the time search has been happening for
float Agent::GetSearchTime()
{
	return m_searchTimer;
}
//gets returns weather agent is at the end of its path or not
bool Agent::GetPathEnd()
{
	return m_pathEnd;
}
//returns whether agent is chasing the player
bool Agent::GetChase()
{
	return m_chase;
}
//returns current node
const Node* Agent::GetCurrentNode()
{
	return m_currentNode;
}
//returns whether player has been caught or not
bool Agent::GetCaptured()
{
	return m_captured;
}
//returns current position
void Agent::SetPosition(glm::vec2 p)
{
	m_position = p;
}
//sets the agent sprite
void Agent::SetSprite()
{
	m_sprite = new aie::Texture("../bin/Sprites/Agent.png");
}

//sets agent velocity
void Agent::SetVelocity(glm::vec2 v)
{
		m_velocity = v;
		m_position += m_velocity;
}
//set the current node
void Agent::setCurrentNode(std::list<const Node *>::iterator n)
{
	m_currentNode = (*n);
}
//set path end
void Agent::AtPathEnd(bool p)
{
	m_pathEnd = p;
}
//sets chase
void Agent::SetChase(bool c)
{
	m_chase = c;
}
