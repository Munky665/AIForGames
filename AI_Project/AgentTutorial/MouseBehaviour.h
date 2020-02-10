#pragma once
#include "Agent.h"
#include "Behaviour.h"


class MouseBehaviour :
	public IBehaviour
{
public:
	MouseBehaviour(Agent* a, std::vector<Node> nodelist);
	virtual ~MouseBehaviour();

	virtual glm::vec2 Update(Agent* a, float deltaTime, std::vector<Node> node);

	void ResetGraph(std::vector<Node> node);


protected:
	
	int tileSize = 64;
	int map_x_dim = 32;
	int maxValue = std::numeric_limits<float>::max();

	std::list<const Node*> m_path;

	std::vector<int> MapData;

	std::list<const Node*>::iterator currentNode;

	Node* begin;
	Node* end;

	int offsetX = 640;
	int offsetY = 210;

};

