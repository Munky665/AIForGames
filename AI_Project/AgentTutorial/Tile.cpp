#include "Tile.h"



Tile::Tile(int texture, int x, int y, bool walkable)
{
	id = texture;
	m_tile = GetTexture(texture);
	PosX = x;
	PosY = y;
	this->walkable = walkable;
}

Tile::Tile(aie::Texture* tile)
{
	m_tile = tile;
}

void Tile::Draw(aie::Renderer2D * renderer)
{
	if(m_tile != nullptr)
	renderer->drawSprite(m_tile, PosX, PosY);
}


Tile::~Tile()
{
}

aie::Texture* Tile::GetTexture(int texture)
{
	aie::Texture* temp;
	switch (texture)
	{
	case 0:
		temp = new aie::Texture("../bin/Sprites/Blank.png");
		break;
	case 1:
		temp = new aie::Texture("../bin/Sprites/FloorTile.png");
		break;
	case 2:
		temp = new aie::Texture("../bin/Sprites/HorizontalWallTile.png");
		break;
	case 3:
		temp = new aie::Texture("../bin/Sprites/VerticalWallTile.png");
		break;
	case 4:
		temp = new aie::Texture("../bin/Sprites/HorizontalDoorTile.png");
		break;
	case 5:
		temp = new aie::Texture("../bin/Sprites/VerticalDoorTile.png");
		break;
	case 6:
		temp = new aie::Texture("../bin/Sprites/TopRightWallTile.png");
		break;
	case 7:
		temp = new aie::Texture("../bin/Sprites/TopLeftWallTile.png");
		break;
	case 8:
		temp = new aie::Texture("../bin/Sprites/BottomRightWallTile.png");
		break;
	case 9:
		temp = new aie::Texture("../bin/Sprites/BottomLeftWallTile.png");
		break;
	}

	return temp;
}
aie::Texture* Tile::GetTexture()
{
	return m_tile;
}

int Tile::GetId()
{
	return id;
}