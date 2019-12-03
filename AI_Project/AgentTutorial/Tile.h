#pragma once
#include <Texture.h>
class Tile
{
	aie::Texture* m_tile;
	int xCoordinate;
	int YCoordinate;
public:
	Tile(const char* string);
	~Tile();
};

