#include "AgentTutorialApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Tile.h"

#include "Pathfinding.h"
#include <iostream>

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
	m_font = new aie::Font("../bin/font/consolas.ttf", tileSize);
	
	nodeList.resize(map_x_dim * map_y_dim );
	MakeGrid();
	int x = 0;
	for (int i = 0; i < map_x_dim; ++i)
	{
		for (int j = 0; j < map_y_dim ; ++j)
		{
			nodeList[x].id = x;
			nodeList[x].position.x = currentLevel->GetTile(x)->GetPosition().x;
			nodeList[x].position.y = currentLevel->GetTile(x)->GetPosition().y;
			x++;
		}
	}
	begin = &nodeList[37];
	end = &nodeList[0];

	m_path.push_back(begin);
	currentNode = m_path.begin();

	m_player = (*currentNode)->position;
	lastStopped = (*currentNode)->id;

	//setup player agent
	//m_player = new Agent(glm::vec2(nodeList[0].position), 20, 20);
	//m_player->SetSprite("../bin/Sprites/Player.png");
	//m_keyboardBehaviour = new MouseBehaviour(m_player, nodeList);
	//m_player->AddBehaviour(m_keyboardBehaviour);

	//setup Enemy Agent
	//m_enemy = new Agent(nodeList[50].position, 150, 500);
	//m_enemy->SetSprite("");
	//m_stateMachine = new FSM();
	//m_enemy->AddBehaviour(m_stateMachine);
	//set states
	//auto attackState = new AttackState(m_player, 100);
	//auto idleState = new IdleState();
	////set conditions
	//auto inRange = new WithinRange(m_player, 200);
	//auto notInRange = new ConditionalNOT(inRange);
	////set state transitions
	//auto toAttackTransition = new Transition(attackState, inRange);
	//auto toIdleTransition = new Transition(idleState, notInRange);
	////add transitions to states
	//idleState->AddTrasition(toAttackTransition);
	//attackState->AddTrasition(toIdleTransition);
	////add states to state machine
	//m_stateMachine->AddState(attackState);
	//m_stateMachine->AddState(idleState);
	////add transition to attack state
	//m_stateMachine->AddTransition(toAttackTransition);
	//m_stateMachine->AddCondition(inRange);
	////add transition to idole state
	//m_stateMachine->AddTransition(toIdleTransition);
	//m_stateMachine->AddCondition(notInRange);

	////set defualt state
	//m_stateMachine->SetCurrentState(idleState);

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

	if (input->wasMouseButtonPressed(0))
	{
		int x = (input->getMouseX() + cameraX) / tileSize;
		int y = (input->getMouseY() + cameraY) / tileSize;

		ResetGraph(nodeList);

		int index = x + y * map_x_dim;

		std::cout << index << std::endl;

		begin = &nodeList[lastStopped];
		end = &nodeList[index];

		m_path = DijkstraSearch(begin, end);

		currentNode = m_path.begin();
	}

	if (currentNode != m_path.end())
	{
		auto gribble_vector = (*currentNode)->position - m_player;
		if (glm::length(gribble_vector) < 1.0f)
		{
			lastStopped = (*currentNode)->id;
			currentNode++;
		}
		else
		{
			const auto NormalVec = glm::normalize(gribble_vector);
			m_player += NormalVec * 100.0f * deltaTime;
		}
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	
	//m_enemy->Update(deltaTime, nodeList);
	//m_player->Update(deltaTime, nodeList);

}

void AgentTutorialApp::draw() {

	// wipe the screen to the background colour
	clearScreen();


	// begin drawing sprites
	m_2dRenderer->begin();
	//get player position and move camera
	m_2dRenderer->getCameraPos(cameraX, cameraY);
	m_2dRenderer->setCameraPos(m_player.y - cameraOffsetY, m_player.x - cameraOffsetX ); //Initilize if map is implemented
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	currentLevel->DrawFloor(m_2dRenderer);
	// draw your stuff here!
	m_2dRenderer->drawCircle(m_player.y, m_player.x, 32);
	
	//m_enemy->Draw(m_2dRenderer);
	
	currentLevel->DrawDoors(m_2dRenderer);

	for (int i = 0; i < map_x_dim * map_y_dim; ++i)
	{
		if (currentLevel->GetTile(i)->IsWalkable() == true) 
		{
			m_2dRenderer->setRenderColour(1, 0, 1, 1);
			m_2dRenderer->drawCircle(nodeList[i].position.x, nodeList[i].position.y, 5);
		}
		else if(currentLevel->GetTile(i)->IsWalkable() == false)
		{
			m_2dRenderer->setRenderColour(0, 1, 1, 1);
			m_2dRenderer->drawCircle(nodeList[i].position.x, nodeList[i].position.y, 5);
		}

	}
	
	//draw line
	if (m_path.size() > 2)
	{
		for (auto i = m_path.begin(), j = std::next(m_path.begin()); j != m_path.end(); ++i, ++j)
		{
			unsigned int id = (*i)->id;
			unsigned int jd = (*j)->id;

			float jx = (id/map_x_dim) * tileSize;
			float jy = (id%map_y_dim) * tileSize;
			float ix = (jd/map_x_dim) * tileSize;
			float iy = (jd%map_y_dim) * tileSize;
			m_2dRenderer->setRenderColour(0, 1, 0, 1);
			
			m_2dRenderer->drawLine(iy, ix, jy, jx, 4, 0);
		}
	}

	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void AgentTutorialApp::MakeGrid()
{
	for (int i = 0; i < map_x_dim * map_y_dim; ++i)
	{
		
		//check if previous node can be connected to
		if (i % map_x_dim != 0)
		{
			if (currentLevel->GetTile(i)->IsWalkable() == true)
				nodeList[i].connections.push_back(Edge{ &nodeList[i - 1], 1.0f });
			else if (currentLevel->GetTile(i)->IsWalkable() == false)
				nodeList[i].connections.push_back(Edge{ &nodeList[i - 1], 1000000.0f });
		}
		//check if next node can be connected to
		if ((i + 1) % map_y_dim != 0)
		{
			if (currentLevel->GetTile(i)->IsWalkable() == true)
				nodeList[i].connections.push_back(Edge{ &nodeList[i + 1], 1.0f });
			else if (currentLevel->GetTile(i)->IsWalkable() == false)
				nodeList[i].connections.push_back(Edge{ &nodeList[i + 1], 1000000.0f });
		}
		//check if node above can be connected to
		if (i / map_x_dim != map_y_dim - 1)
		{
			if (currentLevel->GetTile(i)->IsWalkable() == true)
				nodeList[i].connections.push_back(Edge{ &nodeList[i + map_x_dim], 1.0f });
			else if (currentLevel->GetTile(i)->IsWalkable() == false)
				nodeList[i].connections.push_back(Edge{ &nodeList[i + map_x_dim], 1000000.0f });

		}
		//check if node below can be connected to
		if (i / map_x_dim != 0)
		{
			if (currentLevel->GetTile(i)->IsWalkable() == true)
				nodeList[i].connections.push_back(Edge{ &nodeList[i - map_x_dim], 1.0f });
			else if (currentLevel->GetTile(i)->IsWalkable() == false)
				nodeList[i].connections.push_back(Edge{ &nodeList[i - map_x_dim], 1000000.0f });

		}
	}

}
void AgentTutorialApp::ResetGraph(std::vector<Node> node)
{
	for (auto& i : node)
	{
		i.gScore = std::numeric_limits<float>::max();
	}
}