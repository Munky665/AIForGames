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
	int m_firstRoom = 0;
	int m_lastRoom = 6;
	int m_exitTile = 16;
	int m_gemTile = 17;

	float camX = 0;
	float camY = 0;

	std::vector<Agent*> m_agents;

	MapLoader* m_map;
};