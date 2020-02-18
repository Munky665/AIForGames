#pragma once
#include "Edge.h"
#include <vector>
#include <list>
#include <limits>
#include <glm/glm.hpp>

class Node {
public:
	glm::vec2 position{ 0,0 };
	float gScore = std::numeric_limits<float>::max();
	float hScore = 0;
	float fScore = 0;
	Node* parent = nullptr;
	unsigned int id = 0;
	std::list<Edge> connections;
};

