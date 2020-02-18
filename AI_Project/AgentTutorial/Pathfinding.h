#pragma once
#include <unordered_set>
#include <algorithm>
#include "Node.h"


static int Heuristic(Node* a, Node* b)
{
	int h = (std::sqrt(a->position.x - b->position.x) *(a->position.x - b->position.x))
		+ (a->position.y - b->position.y) * (a->position.y - b->position.y);
	return h;
}

static std::list<const Node*> DijkstraSearch(Node* startNode, Node* endNode)
{

	if (!startNode || !endNode)
	{
		throw std::runtime_error("Null nodes passed in!");

	}
	if (startNode == endNode)
	{
		return std::list<const Node*>();
	}

	startNode->gScore = 0;
	startNode->parent = nullptr;

	std::vector<Node*> openList;
	std::unordered_set<const Node*> closedList;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		auto sortNodes = [](const Node* a, const Node* b)
		{
			return a->fScore < b->fScore;
		};

		std::sort(openList.begin(), openList.end(), sortNodes);

		Node* currentNode = openList.front();

		if (currentNode == endNode)
			break;

		openList.erase(openList.begin());
		closedList.insert(currentNode);

		for (auto& c : currentNode->connections)
		{
			if (std::find(closedList.begin(), closedList.end(), c.target) == closedList.end())
			{
				float gScore = currentNode->gScore + c.cost;
				float hScore = Heuristic(c.target, endNode);
				float fScore = gScore + hScore;


				if (std::find(openList.begin(), openList.end(), currentNode) == openList.end())
				{
					c.target->gScore = gScore;
					c.target->fScore = fScore;
					c.target->parent = currentNode;
					openList.push_back(c.target);
				}
				else if (fScore < c.target->fScore)
				{
					c.target->gScore = gScore;
					c.target->fScore = fScore;
					c.target->parent = currentNode;

				}
			}
		}
	}
	std::list<const Node*> path;
	Node* currentNode = endNode;
	if (!endNode->parent)
		return path;

	while (currentNode)
	{
		path.push_front(currentNode);
		currentNode = currentNode->parent;
	}
	return path;
}
