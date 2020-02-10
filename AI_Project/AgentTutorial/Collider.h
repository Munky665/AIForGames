#pragma once
#include<glm/glm.hpp>

class Agent;
class Tile;
class Rect;


class Collider
{

public:

	Collider();
	static int CheckCollision(Rect* one, Rect* two, glm::vec2 vel);
	~Collider();
	

};

