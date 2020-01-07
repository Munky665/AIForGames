#pragma once
#include <vector>
#include "Tile.h"

class Agent;
class Level
{
private:
	//2d array of tile pointers
	Tile* map[36][36];

	int w, h;

	void SetDimensions(int w, int h);
public:
	Level();
	Level(int w, int h);
	~Level();

	static void AddTile(int srcX, int srcY, int xPos, int yPos);
	Tile* GetTile(int x, int y);
	void CheckCollision(Agent* agent);
	void LoadLevel();
	int GetWidth();
	int GetHeight();
	void DrawFloor(aie::Renderer2D * renderer);
	void DrawDoors(aie::Renderer2D* renderer);
};

