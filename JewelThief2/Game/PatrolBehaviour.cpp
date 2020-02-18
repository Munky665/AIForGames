#include "PatrolBehaviour.h"
#include "MapLoader.h"
#include "Agent.h"
#include "Room.h"
#include "Tile.h"
#include "Pathfinding.cpp"
#include <random>

PatrolBehaviour::PatrolBehaviour(Agent* a, MapLoader* map)
{
		m_begin = map->GetCurrentRoom()->GetNodeMap()[150];
		m_end = map->GetCurrentRoom()->GetNodeMap()[0];

		m_path.push_back(m_begin);
		m_currentNode = m_path.begin();

		lastStopped = (*m_currentNode)->id;

		//14 right bottom
		//23 right top
		//125 mid  top
		//115 mid  bottom
		//239 left top 
		//229 left bottom

		patrolPoints.push_back(map->GetCurrentRoom()->GetNodeMap()[13]);
		patrolPoints.push_back(map->GetCurrentRoom()->GetNodeMap()[22]);
		patrolPoints.push_back(map->GetCurrentRoom()->GetNodeMap()[125]);
		patrolPoints.push_back(map->GetCurrentRoom()->GetNodeMap()[115]);
		patrolPoints.push_back(map->GetCurrentRoom()->GetNodeMap()[238]);
		patrolPoints.push_back(map->GetCurrentRoom()->GetNodeMap()[229]);
}


PatrolBehaviour::~PatrolBehaviour()
{
}


void PatrolBehaviour::MakeDecision(Agent * a, float deltaTime, MapLoader* map)
{

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

const Node& PatrolBehaviour::GetCurrentNode()
{
	return (**m_currentNode);
}

void PatrolBehaviour::SetNext()
{
	target++;
	if (target > patrolPoints.size() - 1)
	{
		target = 0;
	}
}


Node * PatrolBehaviour::GetTargetNode()
{
	return  patrolPoints[target];
}
