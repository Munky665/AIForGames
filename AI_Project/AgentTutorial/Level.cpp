#include "Level.h"
#include <fstream>
#include "Collider.h"
#include "Agent.h"

Level::Level(int w, int h)
{
	SetDimensions(w, h);
	this->w = w;
	this->h = h;
}


Level::~Level()
{
}

int Level::GetHeight()
{
	return h;
}

void Level::DrawFloor(aie::Renderer2D * renderer)
{
	for (int x = 0; x < map.size(); x++)
	{
		for (int y = 0; y < map.size(); y++)
		{
			if(map[x][y]->GetId() != 4 || map[x][y]->GetId() != 5)
			renderer->drawSprite(map[x][y]->GetTexture(), x * 64, y * 64);
		}
	}
}

void Level::DrawDoors(aie::Renderer2D * renderer)
{
	for (int x = 0; x < map.size(); x++)
	{
		for (int y = 0; y < map.size(); y++)
		{
			if (map[x][y]->GetId() == 4 || map[x][y]->GetId() == 5)
				renderer->drawSprite(map[x][y]->GetTexture(), x * 64, y * 64);
		}
	}
}

int Level::GetWidth()
{
	return w;
}

void Level::SetDimensions(int w, int h)
{
	//rows
	map.resize(w);

	//each row has h colums of null tile pointers
	for (int i = 0; i < 2; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int srcX, int srcY, int xPos, int yPos)
{
	
}

Tile * Level::GetTile(int x, int y)
{
	return map[x][y];
}

void Level::CheckCollision(Agent * agent)
{
	for (int x = 0; x < map.size(); x++)
	{
		for (int y = 0; y < map.size(); y++)
		{
			if (Collider::CheckCollision(agent, map[x][y]) == true)
			{
				agent->SetVelocity(Vector2(0, 0));
			}
		}
	}
}

void Level::LoadLevel()
{
	Tile* b   = new Tile(0, 0, 0, false);
	Tile* f   = new Tile(1, 0, 0, true);
	Tile* hw  = new Tile(2, 0, 0, false);
	Tile* vw  = new Tile(3, 0, 0, false);
	Tile* hd  = new Tile(4, 0, 0, true);
	Tile* vd  = new Tile(5, 0, 0, true);
	Tile* trw = new Tile(6, 0, 0, false);
	Tile* tlw = new Tile(7, 0, 0, false);
	Tile* brw = new Tile(8, 0, 0, false);
	Tile* blw = new Tile(9, 0, 0, false);
		//	   0  1  2  3  4  5  6  7   8  9  10 11  12  13  14  15  16  17  18  19  20   21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
	map = { {blw,vw,vw,vw,vw,vw,vw,vw,vw,vw,vw, vw, vw, vw, vw, vw, vw, vw, vw, vw, tlw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hd,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hd, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{brw,vw,vw,vw,vw,vw,vw,vd,vw,vw,vw, vw, vw, vw, vw, vw, vw, vw, vd, vw,  trw, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw,vw,vw,vw,vw, vw,vw,  vw,vw,  vw, vw, vw, vd, vw,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hd,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
			{  b, b, b, b, b, b,hw,vw,vw,vw,vw, vw,vw,  vw,vw,  vw, vw, vw, vw, vw,  vw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b } };

	for (int x = 0; x < map.size(); x++)
	{
		for (int y = 0; y < map.size(); y++)
		{
			map[x][y]->SetPosition(x * 64, y * 64);
		}
	}
}

