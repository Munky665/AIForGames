#pragma once
#include <vector>
#include "Tile.h"

class Level
{
private:
	//2d array of tile pointers
	std::vector<std::vector<Tile*>> map;

	int w, h;

	void SetDimensions(int w, int h);
public:
	Level(int w, int h);
	~Level();

	static void AddTile(int srcX, int srcY, int xPos, int yPos);
	Tile* GetTile(int x, int y);

	void LoadLevel();
	int GetWidth();
	int GetHeight();
	void DrawFloor(aie::Renderer2D * renderer);
	void DrawDoors(aie::Renderer2D* renderer);
};

