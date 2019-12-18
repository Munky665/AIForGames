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
	setBackgroundColour(0.475, 0.475, 0.475, 1);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	currentLevel = new Level(100,100);
	currentLevel->LoadLevel();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_player = new Agent(Vector2(100.0f, 100.0f),Vector2(0,0), 150, 500);
	m_player->SetSprite("../bin/Sprites/Player.png");
	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour);
	cameraOffsetX = getWindowWidth() / 2;
	cameraOffsetY = (getWindowHeight() - 300) / 2;
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
	
}

void AgentTutorialApp::draw() {

	// wipe the screen to the background colour
	clearScreen();


	// begin drawing sprites
	m_2dRenderer->begin();
	//get player position and move camera

	m_2dRenderer->setCameraPos(m_player->GetPosition().x - cameraOffsetX, m_player->GetPosition().y - cameraOffsetY ); //Initilize if map is implemented
	currentLevel->DrawFloor(m_2dRenderer);
	// draw your stuff here!
	m_player->Draw(m_2dRenderer);
	currentLevel->DrawDoors(m_2dRenderer);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

