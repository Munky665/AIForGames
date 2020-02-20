#include "PatrolBehaviour.h"
#include "MapLoader.h"
#include "Agent.h"
#include "Room.h"
#include "Tile.h"
#include "Pathfinding.cpp"
#include <random>

PatrolBehaviour::PatrolBehaviour(Agent* a, MapLoader* map)
{
		m_begin = map->GetRoom(a->GetRoomNumber())->GetNodeMap()[150];
		m_end = map->GetRoom(a->GetRoomNumber())->GetNodeMap()[0];

		m_path.push_back(m_begin);
		m_currentNode = m_path.begin();

		lastStopped = (*m_currentNode)->id;


		for (int i = 0; i < m_waypoints; i++)
		{
			int randomNumber = 1;
			while (map->GetRoom(a->GetRoomNumber())->GetTile(randomNumber)->IsWalkable() == false)
			{
				randomNumber = (int)rand() % 229 + 14;
			}
			patrolPoints.push_back(map->GetRoom(a->GetRoomNumber())->GetNodeMap()[randomNumber] );
		}
}


PatrolBehaviour::~PatrolBehaviour()
{
}


void PatrolBehaviour::MakeDecision(Agent * a, float deltaTime, MapLoader* map)
{
	if (a->GetChase() == false) {
		if (m_currentNode != m_path.end())
		{
			auto moveVec = (*m_currentNode)->position - a->GetPosition();
			if (glm::length(moveVec) < 1.0f)
			{
				lastStopped = (*m_currentNode)->id;
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

			m_begin = map->GetCurrentRoom()->GetNodeMap()[lastStopped];
			m_end = patrolPoints[target];

			m_path = DijkstraSearch(m_begin, m_end);

			m_currentNode = m_path.begin();
		}
	}
}

const Node& PatrolBehaviour::GetCurrentNode()
{
	return (**m_currentNode);
}

void PatrolBehaviour::SetNext()
{
	target++;
	if (target > 5)
	{
		target = 0;
	}
}


Node * PatrolBehaviour::GetTargetNode()
{
	return  patrolPoints[target];
}
