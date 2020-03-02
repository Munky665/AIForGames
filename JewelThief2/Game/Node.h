#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <list>
#include <limits>
#include "Edge.h"

class Node {
public:
	glm::vec2 position{ 0,0 };
	float gScore = std::numeric_limits<float>::max();
	float hScore = 0;
	float fScore = 0;
	bool walkable;
	Node* parent = nullptr;
	int id = 0;
	std::list<Edge> connections;
};