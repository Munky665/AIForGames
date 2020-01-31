#include "AgentTutorialApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "FSMState.h"

AgentTutorialApp::AgentTutorialApp() {

}

AgentTutorialApp::~AgentTutorialApp() {

}

bool AgentTutorialApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	setBackgroundColour(0.475, 0.475, 0.475, 1);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	currentLevel = new Level(36, 36);
	currentLevel->LoadLevel();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	
	//setup player agent
	m_player = new Agent(Vector2(currentLevel->GetTile(1,1)->GetPosition()), 150, 500);
	m_player->SetSprite("../bin/Sprites/Player.png");
	m_keyboardBehaviour = new KeyboardBehaviour();
	m_player->AddBehaviour(m_keyboardBehaviour);

	//setup Enemy Agent
	m_enemy = new Agent(currentLevel->GetTile(8, 1)->GetPosition(), 150, 500);
	m_enemy->SetSprite("");
	m_stateMachine = new FSM();
	m_enemy->AddBehaviour(m_stateMachine);
	//set states
	auto attackState = new AttackState(m_player, 100);
	auto idleState = new IdleState();
	//set conditions
	auto inRange = new WithinRange(m_player, 200);
	auto notInRange = new ConditionalNOT(inRange);
	//set state transitions
	auto toAttackTransition = new Transition(attackState, inRange);
	auto toIdleTransition = new Transition(idleState, notInRange);
	//add transitions to states
	idleState->AddTrasition(toAttackTransition);
	attackState->AddTrasition(toIdleTransition);
	//add states to state machine
	m_stateMachine->AddState(attackState);
	m_stateMachine->AddState(idleState);
	//add transition to attack state
	m_stateMachine->AddTransition(toAttackTransition);
	m_stateMachine->AddCondition(inRange);
	//add transition to idole state
	m_stateMachine->AddTransition(toIdleTransition);
	m_stateMachine->AddCondition(notInRange);

	//set defualt state
	m_stateMachine->SetCurrentState(idleState);

	cameraOffsetX = getWindowWidth() / 2;
	cameraOffsetY = (getWindowHeight() - playerOffset) / 2;
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
	
	m_enemy->Update(deltaTime, *currentLevel);
	m_player->Update(deltaTime, *currentLevel);

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
	m_enemy->Draw(m_2dRenderer);
	currentLevel->DrawDoors(m_2dRenderer);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

