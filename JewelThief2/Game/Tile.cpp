#include "Tile.h"
#include "Rect.h"
#include <Texture.h>


Tile::Tile(int id, int h, int w, glm::vec2 pos)
{
	m_id = id;
	SetSprite(m_id);
	m_height = h;
	m_width = w;
	m_position = pos;
	m_collider = new Rect(m_position.x, m_position.y, h, w);
	
	
	if (id == 3 || id == 2 || id == 14)
	{
		m_walkable = false;
	}
	else m_walkable = true;

}


Tile::~Tile()
{
}

void Tile::Draw(aie::Renderer2D * r)
{
	r->drawSprite(m_sprite, m_position.x, m_position.y);
}

void Tile::SetSprite(int id)
{
	switch (id)
	{
	case 0:
		m_sprite = new aie::Texture("../bin/Sprites/Blank.png");
		break;
	case 1:
		m_sprite = new aie::Texture("../bin/Sprites/FloorTile.png");
		break;
	case 2:
		m_sprite = new aie::Texture("../bin/Sprites/HorizontalWallTile.png");
		break;
	case 3:
		m_sprite = new aie::Texture("../bin/Sprites/VerticalWallTile.png");
		break;
	case 4:
		m_sprite = new aie::Texture("../bin/Sprites/HorizontalDoorTile.png");
		break;
	case 5:
		m_sprite = new aie::Texture("../bin/Sprites/VerticalDoorTile.png");
		break;
	case 6:
		m_sprite = new aie::Texture("../bin/Sprites/TopRightWallTile.png");
		break;
	case 7:
		m_sprite = new aie::Texture("../bin/Sprites/TopLeftWallTile.png");
		break;
	case 8:
		m_sprite = new aie::Texture("../bin/Sprites/BottomRightWallTile.png");
		break;
	case 9:
		m_sprite = new aie::Texture("../bin/Sprites/BottomLeftWallTile.png");
		break;
	case 10:
		m_sprite = new aie::Texture("../bin/Sprites/DoorTileN.png");
		break;
	case 11:
		m_sprite = new aie::Texture("../bin/Sprites/DoorTileE.png");
		break;
	case 12:
		m_sprite = new aie::Texture("../bin/Sprites/DoorTileS.png");
		break;
	case 13:
		m_sprite = new aie::Texture("../bin/Sprites/DoorTileW.png");
		break;
	case 14:
		m_sprite = new aie::Texture("../bin/Sprites/CabnetTile.png");
		break;
	}
}

bool Tile::IsWalkable()
{
	return m_walkable;
}

Rect * Tile::GetCollider()
{
	return m_collider;
}

glm::vec2 Tile::GetPosition()
{
	return m_position;
}

int Tile::GetId()
{
	return m_id;
}

void Tile::SetPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}
