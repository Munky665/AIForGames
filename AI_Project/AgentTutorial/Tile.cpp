#include "Tile.h"



Tile::Tile(int texture, float x, float y)
{
	id = texture;
	m_tile = GetTexture(texture);
	PosX = x;
	PosY = y;
	position = Vector2(x, y);
	collider = new Rect(position.x, position.y, 64, 64);
}

Tile::Tile(aie::Texture* tile)
{
	m_tile = tile;
}

void Tile::Draw(aie::Renderer2D * renderer)
{
	if (m_tile != nullptr) {
		renderer->drawSprite(m_tile, position.x, position.y);
	}
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
		this->walkable = true;
		break;
	case 1:
		temp = new aie::Texture("../bin/Sprites/FloorTile.png");
		this->walkable = true;
		break;
	case 2:
		temp = new aie::Texture("../bin/Sprites/HorizontalWallTile.png");
		this->walkable = false;
		break;
	case 3:
		temp = new aie::Texture("../bin/Sprites/VerticalWallTile.png");
		this->walkable = false;
		break;
	case 4:
		temp = new aie::Texture("../bin/Sprites/HorizontalDoorTile.png");
		this->walkable = true;
		break;
	case 5:
		temp = new aie::Texture("../bin/Sprites/VerticalDoorTile.png");
		this->walkable = true;
		break;
	case 6:
		temp = new aie::Texture("../bin/Sprites/TopRightWallTile.png");
		this->walkable = false;
		break;
	case 7:
		temp = new aie::Texture("../bin/Sprites/TopLeftWallTile.png");
		this->walkable = false;
		break;
	case 8:
		temp = new aie::Texture("../bin/Sprites/BottomRightWallTile.png");
		this->walkable = false;
		break;
	case 9:
		temp = new aie::Texture("../bin/Sprites/BottomLeftWallTile.png");
		this->walkable = false;
		break;
	}
		return temp;
}
aie::Texture* Tile::GetTexture()
{
	if (this != nullptr)
		return m_tile;
	else
		return new aie::Texture("");
}

int Tile::GetId()
{
	if(this != nullptr)
	return this->id;
}

Vector2 Tile::GetPosition()
{
	if (this != nullptr)
		return position;
	else
		return Vector2(0, 0);
}

void Tile::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

bool Tile::IsWalkable()
{
	if (this != nullptr)
		return walkable;
	else
		return false;
}
