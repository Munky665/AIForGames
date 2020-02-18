#pragma once

#include "Application.h"
#include "Agent.h"
#include "MouseBehaviour.h"
#include "ImageManager.h"
#include "Level.h"
#include "FSM.h"
#include "FSMState.h"

class AgentTutorialApp : public aie::Application {
public:

	AgentTutorialApp();
	virtual ~AgentTutorialApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void MakeGrid();

	void ResetGraph(std::vector<Node> node);

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	glm::vec2			m_player;
	MouseBehaviour*   m_keyboardBehaviour;

	Agent*				m_enemy;
	FSM*				m_stateMachine;
	
	ImageManager imageManager;

	Level* currentLevel;

	std::vector<Node> nodeList;

	int map_x_dim = 36;
	int map_y_dim = 36;

	float cameraX;
	float cameraY;

	float cameraOffsetX;
	float cameraOffsetY;
	int	  playerOffset = 300;

	int tileSize = 64;
	int lastStopped;
	std::list<const Node*> m_path;

	std::vector<int> MapData;

	std::list<const Node*>::iterator currentNode;

	Node* begin;
	Node* end;
};