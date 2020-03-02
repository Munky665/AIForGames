#include "Room.h"
#include <fstream>
#include <sstream>
#include "Tile.h"
#include "Node.h"

Room::Room(int id)
{
	m_roomId = id;
	LoadFileName();
	LoadMapFile();
	CreateNodeMap();
	MakeGrid();
}


Room::~Room()
{
}

void Room::Draw(aie::Renderer2D* r)
{
	for (Tile* t : m_room)
	{
		t->Draw(r);
	}
}

void Room::LoadFileName()
{
	switch (m_roomId)
	{
	case 0:
		m_fileName = "../bin/rooms/Room1.txt";
		break;
	case 1:
		m_fileName = "../bin/rooms/Room2.txt";
		break;
	case 2:
		m_fileName = "../bin/rooms/Room3.txt";
		break;
	case 3:
		m_fileName = "../bin/rooms/Room4.txt";
		break;
	case 4:
		m_fileName = "../bin/rooms/Room5.txt";
		break;
	case 5:
		m_fileName = "../bin/rooms/Room6.txt";
		break;
	case 6:
		m_fileName = "../bin/rooms/Room7.txt";
		break;
	}
}
//creates nodes for Ai pathfinding graph
void Room::CreateNodeMap()
{
	for (int i = 0; i < m_room.size(); i++)
	{
		m_nodeMap.push_back(new Node());
		m_nodeMap[i]->position.x = m_room[i]->GetPosition().x ;
		m_nodeMap[i]->position.y = m_room[i]->GetPosition().y ;
		m_nodeMap[i]->id = i;
		m_nodeMap[i]->walkable = m_room[i]->IsWalkable();
	}
}

void Room::MakeGrid()
{
	for (int i = 0; i < m_nodeMap.size(); i++)
	{

		//check if previous node can be connected to
		if (i % m_mapX != 0)
		{
			if (m_nodeMap[i]->walkable == true)
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i - 1], 1.0f });
			else if (m_nodeMap[i]->walkable == false)
			{
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i - 1], std::numeric_limits<float>::max() });
			}

		}
		//check if next node can be connected to
		if ((i + 1) % m_mapY != 0)
		{
			if (m_nodeMap[i]->walkable == true)
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i + 1], 1.0f });
			else if (m_nodeMap[i]->walkable == false)
			{
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i + 1], std::numeric_limits<float>::max() });
			}
		}
		//check if node above can be connected to
		if (i / m_mapX != m_mapY - 1)
		{
			if (m_nodeMap[i]->walkable == true)
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i + m_mapY], 1.0f });
			else if (m_nodeMap[i]->walkable == false)
			{
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i + m_mapY], std::numeric_limits<float>::max() });
			}

		}
		//check if node below can be connected to
		if (i / m_mapY != 0)
		{
			if (m_nodeMap[i]->walkable == true)
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i - m_mapY], 1.0f });
			else if (m_nodeMap[i]->walkable == false)
			{
				m_nodeMap[i]->connections.push_back(Edge{ m_nodeMap[i - m_mapY], std::numeric_limits<float>::max() });
			}
			

		}
	}

}

void Room::LoadMapFile()
{
	//open mapfile
	std::ifstream fileIn;
	fileIn.open(m_fileName, std::ios::in);
	int tileId[21][21];
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
				if (s != "n")record.push_back(s);
			}
			record.resize(12);
			for (int i = 0; i < record.size(); i++)
			{
				tileId[x][i] = std::stoi(record[i]);
			}
			x++;
		}
		fileIn.close();
	}

	int i = 0;
	for (int x = 0; x < 21; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			Tile* temp = new Tile(tileId[x][y], m_tileSize, m_tileSize, glm::vec2(x* m_tileSize, y* m_tileSize));
			m_room.push_back(temp);
			i++;
		}
	}
}

int Room::GetRoomId()
{
	return m_roomId;
}

Tile * Room::GetTile(int i)
{
	return m_room[i];
}

std::vector<Tile*> Room::GetMap()
{
	return m_room;
}

std::vector<Node*> Room::GetNodeMap()
{
	return m_nodeMap;
}
