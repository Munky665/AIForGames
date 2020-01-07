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
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++) {
			if (map[x][y]->GetId() != 4 || map[x][y]->GetId() != 5)
					map[x][y]->Draw(renderer);
		}
	}
}

void Level::DrawDoors(aie::Renderer2D * renderer)
{
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++) {
			if (map[x][y]->GetId() == 4 || map[x][y]->GetId() == 5)
				map[x][y]->Draw(renderer);
				//renderer->drawSprite(map[x][y]->GetTexture(), map[x][y]->GetPosition().x, map[x][y]->GetPosition().y, 64, 64);
		}
	}
}

int Level::GetWidth()
{
	return w;
}

void Level::SetDimensions(int w, int h)
{

	//each row has h colums of null tile pointers
	for (int i = 0; i < 2; i++)
	{
		
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
	/*for (int x = 0; x < 64; x++)
	{

		if (Collider::CheckCollision(agent, map[x]) == true)
		{
			agent->SetVelocity(Vector2(0, 0));
		}

	}*/
}

void Level::LoadLevel()
{

	std::ifstream fileIn;
	fileIn.open("../bin/MapLayout.txt", std::ios::in);
	int id[36][36];
	int x = 0;
	int y = 0;


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


	for (x = 0; x < w; x++)
	{
		for (y = 0; y < h; y++)
		{
			Tile* temp = new Tile(id[x][y], (x * 64), (y * 64));
			temp->SetPosition(x * 64, y * 64);
			map[x][y] = temp;
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

