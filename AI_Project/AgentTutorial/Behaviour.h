#pragma once
#define _USE_MATH_DEFINES
#include <glm/glm.hpp>
#include <vector>
#include <cmath>

class Node;
class Agent;
class Level;
class IBehaviour
{
public:
	IBehaviour();
	//pure virtual function for executing the behaviour
	virtual glm::vec2 Update(Agent* ptr, float deltaTime, std::vector<Node> node) = 0;
	virtual~IBehaviour();
	
};

