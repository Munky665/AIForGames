#pragma once

class Player;
class Agent;
class MapLoader;

class IBehaviour
{
public:
	IBehaviour();

	virtual void Update(Player* p, float deltaTime, MapLoader* map) = 0;
	virtual bool Update(Agent* a, float deltaTime) = 0;
	~IBehaviour();
};

