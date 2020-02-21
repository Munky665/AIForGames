#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Agent;
class Player;
class IBehaviour;
class MapLoader;

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

	Player* m_player;
	IBehaviour* b_key;
	int m_currentRoom;
	
	float camX = 0;
	float camY = 0;

	Agent* m_enemy;
	Agent* m_enemyR2;

	MapLoader* m_map;
};