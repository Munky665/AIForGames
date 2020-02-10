
#include <glm/glm.hpp>
#include <vector>
#include <list>
#include <limits>

class Edge;
class Node;

class Node {
public:
	glm::vec2 position{ 0,0 };
	float gScore = std::numeric_limits<float>::max();
	Node* parent = nullptr;

	std::list<Edge> connections;
};

class Edge
{
public:
	Node* target;
	float cost;

};