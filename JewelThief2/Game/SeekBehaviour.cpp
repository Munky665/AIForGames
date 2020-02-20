#include "SeekBehaviour.h"
#include "Player.h"
#include "MapLoader.h"
#include "Node.h"
#include "Room.h"
#include "Collider.cpp"
#include "Tile.h"
#include "Agent.h"
#include "Pathfinding.cpp"

SeekBehaviour::SeekBehaviour(Player* p, MapLoader* map)
{
	m_player = p;
	m_begin = map->GetCurrentRoom()->GetNodeMap()[150];
	m_end = map->GetCurrentRoom()->GetNodeMap()[22];

	m_path.push_back(m_begin);
	m_currentNode = m_path.begin();

}


SeekBehaviour::~SeekBehaviour()
{
}

void SeekBehaviour::MakeDecision(Agent * a, float deltaTime, MapLoader * map)
{
	if (a->GetChase() == false)
	{
		m_lastStopped = a->GetCurrentNode()->id;
		m_begin = map->GetCurrentRoom()->GetNodeMap()[m_lastStopped];
		m_currentNode = m_path.begin();
	}
	if (m_c->Test(a))
	{

		if (m_currentNode != m_path.end())
		{
			auto moveVec = (*m_currentNode)->position - a->GetPosition();
			if (glm::length(moveVec) < 1.0f)
			{
				m_lastStopped = (*m_currentNode)->id;
				m_currentNode++;
			}
			else
			{
				const auto normalVec = glm::normalize(moveVec);
				a->SetVelocity(normalVec * 100.0f * deltaTime);
			}
		}

		if (m_currentNode == m_path.end())
		{

			m_begin = map->GetCurrentRoom()->GetNodeMap()[m_lastStopped];
			m_end = map->GetCurrentRoom()->GetNodeMap()[m_target];

			m_path = DijkstraSearch(m_begin, m_end);

			m_currentNode = m_path.begin();
		}
		m_target = FindTarget(map);
	}
}

const Node& SeekBehaviour::GetCurrentNode()
{
	return **m_currentNode;
}


Node * SeekBehaviour::GetTargetNode()
{
	return nullptr;
}
//loop through tile list till tile with player collision located then return node that is equivilent
int SeekBehaviour::FindTarget(MapLoader* map)
{
	int x = 0;

	for (Tile* n : map->GetCurrentRoom()->GetMap())
	{

		if (CheckCollision(m_player->GetCollider(), n->GetCollider(), glm::vec2(0,0)) == true)
		{
			return map->GetCurrentRoom()->GetNodeMap()[x]->id;
		}
		x++;
	}
}