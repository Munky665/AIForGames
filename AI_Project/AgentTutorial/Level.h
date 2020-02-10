#pragma once
#include <vector>
#include "Tile.h"

class Agent;
class Level
{
private:
	//2d array of tile pointers
	std::vector<Tile*> map;

	int w, h;

	int tileSize = 64;

public:
	Level();
	Level(int w, int h);
	~Level();

	Tile* GetTile(int x);
	void LoadLevel();
	int GetWidth();
	int GetHeight();
	void DrawFloor(aie::Renderer2D * renderer);
	void DrawDoors(aie::Renderer2D* renderer);
};

