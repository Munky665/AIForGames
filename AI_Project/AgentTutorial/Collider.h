#pragma once

class Agent;
class Tile;

class Collider
{
public:
	Collider();
	static bool CheckCollision(Agent* agent, Tile* tile);
	~Collider();
};

