#include "Level.h"
#include <fstream>
#include "Collider.h"
#include "Agent.h"
#include <sstream>

Level::Level()
{
}

Level::Level(int w, int h)
{
	this->w = w;
	this->h = h;
	map.resize(w*h);
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
	for (Tile* t : map)
	{
		if (t->GetId() != 4 || t->GetId() != 5)
			t->Draw(renderer);

	}
}

void Level::DrawDoors(aie::Renderer2D * renderer)
{
	for (Tile* t : map)
	{
		if (t->GetId() == 4 || t->GetId() == 5)
			t->Draw(renderer);
		//renderer->drawSprite(map[x][y]->GetTexture(), map[x][y]->GetPosition().x, map[x][y]->GetPosition().y, tileSize, tileSize);

	}
}

int Level::GetWidth()
{
	return w;
}

Tile* Level::GetTile(int x)
{
	return map[x];
}

void Level::LoadLevel()
{
	//open mapfile
	std::ifstream fileIn;
	fileIn.open("../bin/MapLayout.txt", std::ios::in);
	int id[36][36];
	int x = 0;
	int y = 0;

	//if file open read map details to tile then add tile to array
	if (fileIn.is_open())
	{
		while (!fileIn.eof())
		{
			std::string s;
			if (!std::getline(fileIn, s)) break;
			std::istringstream ss(s);
			std::vector<std::string> record;
			while (ss)
			{
				std::string s;
				if (!std::getline(ss, s, ',')) break;
				if(s != "n")record.push_back(s);
			}
			record.resize(36);
			for (int i = 0; i < record.size(); i++)
			{
				id[x][i] = std::stoi(record[i]);
			}
			x++;
		}
		fileIn.close();
	}

	int i = 0;
	for (x = 0; x < w; x++)
	{
		for (y = 0; y < h; y++)
		{
			Tile* temp = new Tile(id[x][y], (i * tileSize), (i * tileSize));
			temp->SetPosition(x * tileSize , y * tileSize);
			map[i] = temp;
			i++;
		}
	}

	//	//	   0  1  2  3  4  5  6  7   8  9  10 11  12  13  14  15  16  17  18  19  20   21 22 23 24 25 26 27 28 29 30 31 32 33 34 35
	//map = { {blw,vw,vw,vw,vw,vw,vw,vw,vw,vw,vw, vw, vw, vw, vw, vw, vw, vw, vw, vw, tlw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b},
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hd,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hd, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{hw, f, f, f, f, f, hw, f, f, f, f, hw,  f,  f,  f,  f, f ,  f,  f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{brw,vw,vw,vw,vw,vw,vw,vd,vw,vw,vw, vw, vw, vw, vw, vw, vw, vw, vd, vw,  trw, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f, f,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw,vw,vw,vw,vw, vw,vw,  vw,vw,  vw, vw, vw, vd, vw,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b },
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hd,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw, f, f, f, f,  f, f,   f,hw,   f,  f, f,   f,  f,  hw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }, 
	//		{  b, b, b, b, b, b,hw,vw,vw,vw,vw, vw,vw,  vw,vw,  vw, vw, vw, vw, vw,  vw , b, b, b, b, b, b, b, b, b, b, b, b, b, b, b } };

}

