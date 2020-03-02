#include "MapLoader.h"
#include "Room.h"
#include "Player.h"
#include "Collider.cpp"
#include "Tile.h"
#include "Node.h"

MapLoader::MapLoader()
{
	for (int i = 0; i < m_numberOfRooms; ++i)
	{
		m_rooms.push_back(new Room(i));
	}

}

MapLoader::~MapLoader()
{
}

void MapLoader::LoadNextRoom(Player * p)
{
	for (Tile* t : m_rooms[m_currentRoom]->GetMap())
	{
		if (t->GetId() == 4 || t->GetId() == 5)
		{
			if (CheckCollision(t->GetCollider(), p->GetCollider(), glm::vec2(0, 0)))
			{
				switch (m_currentRoom)
				{
				case 0://room 1
					//top door to room 2
					p->SetPosition(glm::vec2(t->GetPosition().x, m_roomBottomPos));
					m_currentRoom = 1;	//connects line 40
					break;
				case 1:// room2
					//bottom door to room one
					if (p->GetPosition().y <= m_roomBottomPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomTopPos));
						m_currentRoom = 0; //connects line 33
					}
					//right door to room 3
					else if (p->GetPosition().x >= m_roomRightPos)
					{
						p->SetPosition(glm::vec2(m_roomLeftPos, t->GetPosition().y));
						m_currentRoom = 2; //connects line 60
					}
					//top door to room 4
					else if (p->GetPosition().y >= m_roomTopPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomBottomPos));
						m_currentRoom = 3; //connects line 74
					}
					break;
				case 2://room3
					//left door to room 2
					if (p->GetPosition().x < m_roomLeftPos)
					{
						p->SetPosition(glm::vec2(m_roomRightPos, t->GetPosition().y));
						m_currentRoom = 1; //connects line 46
					}
					//top door to room 5
					else if (p->GetPosition().y >= m_roomTopPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomBottomPos));
						m_currentRoom = 4; //connects line 88
					}
					break;
				case 3://room4
					//bottom door to room 2
					if (p->GetPosition().y <= m_roomBottomPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomTopPos));
						m_currentRoom = 1; //connects line 52
					}
					//right door to room 5
					else if (p->GetPosition().x >= m_roomRightPos)
					{
						p->SetPosition(glm::vec2(m_roomLeftPos, t->GetPosition().y));
						m_currentRoom = 4; //connects line 94
					}
					break;
				case 4: //room5
					//bottom door to room 3
					if (p->GetPosition().y <= m_roomBottomPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomTopPos));
						m_currentRoom = 2; //connects line 66
					}
					//left door to room 
					else if (p->GetPosition().x < m_roomLeftPos)
					{
						p->SetPosition(glm::vec2(m_roomRightPos, t->GetPosition().y));
						m_currentRoom = 3;//connects line 80
					}
					//right door
					else if (p->GetPosition().x >= m_roomRightPos)
					{
						p->SetPosition(glm::vec2(m_roomLeftPos, t->GetPosition().y));
						m_currentRoom = 5; //connects line 108
					}
					break;
				case 5: //room6
					//left door
					if (p->GetPosition().x < m_roomLeftPos)
					{
						p->SetPosition(glm::vec2(m_roomRightPos, t->GetPosition().y));
						m_currentRoom = 4; //connects line 100
					}
					//bottom door
					else if (p->GetPosition().y <= m_roomBottomPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomTopPos));
						m_currentRoom = 6; //connects line 122
					}
					break;
				case 6: //room7
					//top door
					if (p->GetPosition().y >= m_roomTopPos)
					{
						p->SetPosition(glm::vec2(t->GetPosition().x, m_roomBottomPos));
						m_currentRoom = 5; //connects line 114
					}
					break;

				}
			}
		}
	}
}

Room* MapLoader::GetCurrentRoom()
{
	return m_rooms[m_currentRoom];
}

Room* MapLoader::GetRoom(int n)
{
	return m_rooms[n];
}

void MapLoader::ChangeRoom(int roomNumber)
{
	m_currentRoom = roomNumber;
}

void MapLoader::ResetGraph()
{
	for (int i = 0; i < GetCurrentRoom()->GetMap().size(); ++i)
	{

		GetCurrentRoom()->GetNodeMap()[i]->gScore = std::numeric_limits<float>::max();

	}
}