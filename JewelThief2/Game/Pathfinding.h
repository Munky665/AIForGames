#pragma once
#include <list>

class Node;


class Pathfinding
{
public:
	static std::list<Node*> AStar(Node * startNode, Node * endNode);

	static float Heuristic(Node* a, Node* b);
};