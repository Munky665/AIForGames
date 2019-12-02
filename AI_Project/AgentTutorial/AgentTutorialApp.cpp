#include "AgentTutorialApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

AgentTutorialApp::AgentTutorialApp() {

}

AgentTutorialApp::~AgentTutorialApp() {

}

bool AgentTutorialApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_player = new Agent(Vector2(100.0f, 100.0f),Vector2(0,0), 150, 500);
	m_player->SetColor(1, 0, 0, 1);
	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour);

	m_enemy = new Agent(Vector2(500.0f, 500.0f), Vector2(0, 0), 120,200);
	m_followerBehaviour = new SeekBehaviour();
	m_enemy->SetColor(0.5, 0.5, 0, 1);
	m_followerBehaviour->SetTarget(m_player);
	m_followerBehaviour->SetSpeed(100);
	m_enemy->AddBehaviour(m_followerBehaviour);

	m_fleeingEnemy = new Agent(Vector2(500, 500), Vector2(0, 0),120,200);
	m_fleeingBehaviour = new FleeBehaviour();
	m_fleeingEnemy->SetColor(0, 1, 0.5, 1);
	m_fleeingBehaviour->SetSpeed(20);
	m_fleeingBehaviour->SetTarget(m_player);
	m_fleeingEnemy->AddBehaviour(m_fleeingBehaviour);

	m_wanderingEnemy = new Agent(Vector2(200,200), Vector2(0,0),50,200);
	m_wanderingEnemy->SetColor(0, 0, 1, 1);
	m_wander = new WanderBehaviour();
	m_wander->SetTarget(Vector2(rand() % 1080 + 500, rand() % 520 + 260));
	m_wander->SetSpeed(100);
	m_wanderingEnemy->AddBehaviour(m_wander);
	return true;
}

void AgentTutorialApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AgentTutorialApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	m_player->Update(deltaTime);
	m_enemy->Update(deltaTime);
	m_fleeingEnemy->Update(deltaTime);
	m_wanderingEnemy->Update(deltaTime);
}

void AgentTutorialApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	//get player position and move camera
	m_2dRenderer->setCameraPos(m_player->GetPosition().x - getWindowWidth() / 2, m_player->GetPosition().y - getWindowHeight() / 2 );
	
	
	// draw your stuff here!
	m_player->Draw(m_2dRenderer);
	m_enemy->Draw(m_2dRenderer);
	m_fleeingEnemy->Draw(m_2dRenderer);
	m_wanderingEnemy->Draw(m_2dRenderer);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}