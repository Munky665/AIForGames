#pragma once
#include <vector>
#include <Renderer2D.h>
class Tile;
class Node;

class Room
{
public:
	Room(int id);
	~Room();

	void LoadMapFile();
	void Draw(aie::Renderer2D* r);
	void LoadFileName();
	void CreateNodeMap();

	void MakeGrid();

	//getter 
	int GetRoomId();
	Tile* GetTile(int i);
	std::vector<Tile*> GetMap();
	std::vector<Node*> GetNodeMap();


	//setter



private:
	std::vector<Tile*> m_room;
	std::vector<Node*>m_nodeMap;
	const char* m_fileName;
	int m_roomId = 0;
	int m_tileSize = 64;
	int m_mapX = 21;
	int m_mapY = 12;
};

