#pragma once
#include <unordered_set>
#include <algorithm>
#include "Edge.h"
#include "Node.h"
#include "Pathfinding.h"


std::list<Node*> Pathfinding::AStar(Node* startNode, Node* endNode)
{
	//check if nodes passed in are not == to null
	if (!startNode || !endNode)
	{
		throw std::runtime_error("Null nodes passed in!");

	}
	//if start and end node are the same return empty list
	if (startNode == endNode)
	{
		return std::list< Node*>();
	}

	//setup new lists and values
	startNode->gScore = 0;
	startNode->parent = nullptr;

	std::vector<Node*> openList;
	std::unordered_set<const Node*> closedList;

	openList.push_back(startNode);

	while (!openList.empty())
	{
		//sort nodes based of fScore
		auto sortNodes = [](const Node* a, const Node* b)
		{
			return a->fScore < b->fScore;
		};

		std::sort(openList.begin(), openList.end(), sortNodes);
		//intialize current node
		Node* currentNode = openList.front();

		if (currentNode == endNode)
			break;

		openList.erase(openList.begin());
		closedList.insert(currentNode);

		for (auto& c : currentNode->connections)
		{
			//check if target is in closed list
			if (std::find(closedList.begin(), closedList.end(), c.target) == closedList.end())
			{
				float gScore = currentNode->gScore + c.cost;
				float hScore = Heuristic(c.target, endNode);
				float fScore = gScore + hScore;

				//if target not in open list calculate score then update parent
				if (std::find(openList.begin(), openList.end(), c.target) == openList.end())
				{
					c.target->gScore = gScore;
					c.target->fScore = fScore;
					c.target->parent = currentNode;
					openList.push_back(c.target);
				}
				//if target in list, compare calculated score with current to find shortest
				else if (fScore < c.target->fScore)
				{
					c.target->gScore = gScore;
					c.target->fScore = fScore;
					c.target->parent = currentNode;

				}
			}
		}
	}
	std::list< Node*> path;
	Node* currentNode = endNode;
	if (!endNode->parent)
		return path;
	//create path in reverse from end to start
	while (currentNode)
	{
		path.push_front(currentNode);
		currentNode = currentNode->parent;
	}
	return path;
}

//basic heurstic function to determine heuristic for aStar algorithm
float Pathfinding::Heuristic(Node* a, Node* b)
{
	auto d = b->position - a->position;
	return abs(d.x) + abs(d.y);

}