#include "SeekBehaviour.h"
#include "Player.h"
#include "MapLoader.h"
#include "Node.h"
#include "Room.h"
#include "Collider.cpp"
#include "Tile.h"
#include "Agent.h"
#include "Pathfinding.h"

SeekBehaviour::SeekBehaviour(Player* p, MapLoader* map)
{
	m_player = p;
	m_begin = map->GetCurrentRoom()->GetNodeMap()[150];
	m_end = map->GetCurrentRoom()->GetNodeMap()[22];

	m_path.push_back(m_begin);
	m_currentNode = m_path.begin();
	map->ResetGraph();
}


SeekBehaviour::~SeekBehaviour()
{
}

void SeekBehaviour::MakeDecision(Agent * a, float deltaTime, MapLoader * map)
{
	if (m_c->Test(a))
	{
		m_target = FindTarget(map);
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

			m_path = Pathfinding::AStar(m_begin, m_end);

			m_currentNode = m_path.begin();

			map->ResetGraph();
		}

	}
}


Node& SeekBehaviour::GetCurrentNode()
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
			//force return of only walkable nodes
			while (map->GetCurrentRoom()->GetTile(x)->IsWalkable() == false)
			{
				x++;
			}
			return map->GetCurrentRoom()->GetNodeMap()[x]->id;
		}
		x++;
	}
}

void SeekBehaviour::SetCurrentNode(Node * n)
{
	m_path.clear();
	m_begin = n;
	m_path.push_back(m_begin);
	m_currentNode = m_path.begin();
}

