#include "Tile.h"



Tile::Tile(const char* string)
{
	m_tile = new aie::Texture(string);
}


Tile::~Tile()
{
}
