#pragma once
#include <MathLib.h>
#include <vector>
#include <list>
#include <limits>

namespace PF {

	struct Node {
		Vector2 position{ 0,0 };
		float gScore = std::numeric_limits<float>::max();
		Node* parent = nullptr;

		std::list<Edge> connections;
	};

	struct Edge
	{
		Node* target;
		float cost;

	};
}