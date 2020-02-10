#include "MouseBehaviour.h"
#include <Input.h>
#include "Pathfinding.h"


MouseBehaviour::MouseBehaviour(Agent* a, std::vector<Node> nodelist)
{
	begin = &nodelist[0];
	end = &nodelist[0];

	m_path.push_back(begin);
	currentNode = m_path.begin();
}


MouseBehaviour::~MouseBehaviour()
{
}

glm::vec2 MouseBehaviour::Update(Agent* a, float deltaTime, std::vector<Node> node)
{
	aie::Input* input = aie::Input::getInstance();
	glm::vec2 force(0, 0);

	if (input->isMouseButtonDown(0))
	{
		int x = (input->getMouseX() - offsetX )/ tileSize;
		int y = (input->getMouseY() - offsetY )/ tileSize;

		ResetGraph(node);

		int index = x + y * map_x_dim;

		begin = &node[(int(a->GetPosition().x / tileSize) + int(a->GetPosition().y / tileSize)) * map_x_dim];
		end = &node[index];

		m_path = DijkstraSearch(begin, end);
		
		currentNode = m_path.begin();
	}

	if (currentNode != m_path.end())
	{
		auto CNodeVec = (*currentNode)->position - a->GetPosition();
		if (glm::length(CNodeVec) < 1.0f)
		{
			currentNode++;
		}
		else
		{
			auto NormalVec = glm::normalize(CNodeVec);
			a->SetPosition(NormalVec * 10.0f * deltaTime);
			return NormalVec;
		}
	}

}


void MouseBehaviour::ResetGraph(std::vector<Node> node)
{
	for (auto& i : node)
	{
		i.gScore = maxValue;
	}
}