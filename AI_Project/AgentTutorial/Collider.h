#pragma once

class Agent;
class Tile;
class Rect;
class Vector2;

class Collider
{

public:

	Collider();
	static int CheckCollision(Rect* one, Rect* two, Vector2 vel);
	~Collider();
	

};

