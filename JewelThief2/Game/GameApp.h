#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>

class Agent;
class Player;
class IBehaviour;
class MapLoader;

enum State
{
	GAMESTATE,
	WIN,
	LOSE
};

class GameApp : public aie::Application {
public:

	GameApp();
	virtual ~GameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	State m_state = GAMESTATE;

	Player* m_player;
	IBehaviour* b_key;
	int m_currentRoom;
	
	float camX = 0;
	float camY = 0;

	Agent* m_enemy;
	Agent* m_enemyR2;
	Agent* m_enemyR31;
	Agent* m_enemyR32;
	Agent* m_enemyR41;
	Agent* m_enemyR42;
	Agent* m_enemyR51;
	Agent* m_enemyR52;
	Agent* m_enemyR61;
	Agent* m_enemyR62;

	std::vector<Agent*> m_agents;

	MapLoader* m_map;
};