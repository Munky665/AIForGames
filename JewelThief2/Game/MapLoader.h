#pragma once

#include <vector>
class Room;
class Player;


class MapLoader
{
public:
	MapLoader();
	~MapLoader();

	void LoadNextRoom(Player* p);

	//getter
	Room* GetCurrentRoom();

	Room * GetRoom(int n);

	//setter
	void ChangeRoom(int roomNumber);

	void ResetGraph();

private:
	std::vector<Room*> m_rooms;

	
	int m_numberOfRooms = 7;
	int m_currentRoom = 0;

	int m_roomBottomPos = 70;
	int m_roomTopPos = 620;
	int m_roomRightPos = 1180;
	int m_roomLeftPos = 65;

};

