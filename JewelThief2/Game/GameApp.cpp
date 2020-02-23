#include "GameApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "MapLoader.h"
#include "Room.h"
#include "Agent.h"
#include "Node.h"
#include "KeybaordBehaviour.h"

GameApp::GameApp() {
	
}

GameApp::~GameApp() {

}

bool GameApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_2dRenderer->getCameraPos(camX, camY);
	m_map = new MapLoader();

	m_player = new Player(m_map->GetCurrentRoom()->GetNodeMap()[14]->position, 100, "../bin/Sprites/Player.png");
	b_key = new KeybaordBehaviour();
	m_player->AddBehaviour(b_key);

	m_enemy = new Agent(0, m_map, m_player);
	m_enemyR2 = new Agent(1, m_map, m_player);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void GameApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void GameApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_currentRoom = m_map->GetCurrentRoom()->GetRoomId();

	m_player->Update(deltaTime, m_map);

	m_enemy->Update(deltaTime, m_map, m_player);

	m_enemyR2->Update(deltaTime, m_map, m_player);


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	m_map->LoadNextRoom(m_player);
}

void GameApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->setCameraPos(camX - 100, camY - 100);
	// draw your stuff here!
	m_map->GetCurrentRoom()->Draw(m_2dRenderer);
	

	m_player->Draw(m_2dRenderer);
	switch (m_currentRoom)
	{
	case 0:
		m_enemy->Draw(m_2dRenderer);
		break;
	case 1:
		m_enemyR2->Draw(m_2dRenderer);
		break;
	default:
		break;
	}
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}