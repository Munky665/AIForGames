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
#include "Rect.h"

GameApp::GameApp() {
	
}

GameApp::~GameApp() {

}

bool GameApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_2dRenderer->getCameraPos(camX, camY);
	m_map = new MapLoader();

	m_player = new Player(m_map->GetCurrentRoom()->GetNodeMap()[14]->position, 100);
	b_key = new KeybaordBehaviour();
	m_player->AddBehaviour(b_key);

	//setup all agents

	m_agents.push_back(new Agent(0, m_map, m_player));
	m_agents.push_back(new Agent(1, m_map, m_player));
	m_agents.push_back(new Agent(2, m_map, m_player));
	m_agents.push_back(new Agent(2, m_map, m_player));
	m_agents.push_back(new Agent(3, m_map, m_player));
	m_agents.push_back(new Agent(3, m_map, m_player));
	m_agents.push_back(new Agent(4, m_map, m_player));
	m_agents.push_back(new Agent(4, m_map, m_player));
	m_agents.push_back(new Agent(5, m_map, m_player));
	m_agents.push_back(new Agent(5, m_map, m_player));

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
	switch (m_state)
	{
	case GAMESTATE:
		m_currentRoom = m_map->GetCurrentRoom()->GetRoomId();
		m_player->Update(deltaTime, m_map);

		//update agents
		for (Agent* a : m_agents)
		{
			a->Update(deltaTime, m_map, m_player);
			if (a->GetCaptured() == true)
			{
				m_state = LOSE;
			}
		}
		break;
	case WIN:

		break;
	case LOSE:
		break;
	default:
		break;
	}

	m_map->LoadNextRoom(m_player);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();


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
		m_agents[0]->Draw(m_2dRenderer);
		break;
	case 1:
		m_agents[1]->Draw(m_2dRenderer);
		break;
	case 2:
		m_agents[2]->Draw(m_2dRenderer);
		m_agents[3]->Draw(m_2dRenderer);
		break;
	case 3:
		m_agents[4]->Draw(m_2dRenderer);
		m_agents[5]->Draw(m_2dRenderer);
		break;
	case 4:
		m_agents[6]->Draw(m_2dRenderer);
		m_agents[7]->Draw(m_2dRenderer);
		break;
	case 5:
		m_agents[8]->Draw(m_2dRenderer);
		m_agents[9]->Draw(m_2dRenderer);
		break;
	}
	switch (m_state)
	{
	case LOSE:
		m_2dRenderer->drawText(m_font, "YOU LOSE", (getWindowWidth() - 300) / 2, getWindowHeight() / 2);
		break;
	case WIN:
		m_2dRenderer->drawText(m_font, "YOU WIN", getWindowHeight() / 2, getWindowWidth() / 2);
		break;
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}