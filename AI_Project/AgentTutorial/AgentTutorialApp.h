#pragma once

#include "Application.h"
#include "Agent.h"
#include "KeyboardBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "WanderBehaviour.h"
#include "ImageManager.h"
#include "Level.h"
#include "FSM.h"

#include "Graph.h"

class AgentTutorialApp : public aie::Application {
public:

	AgentTutorialApp();
	virtual ~AgentTutorialApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Agent*				m_player;
	KeyboardBehaviour*   m_keyboardBehaviour;

	Agent*				m_enemy;
	FSM*				m_stateMachine;

	Agent*				m_fleeingEnemy;
	FleeBehaviour*      m_fleeingBehaviour;

	Agent*				m_wanderingEnemy;
	WanderBehaviour*	m_wander;
	
	ImageManager imageManager;

	Level* currentLevel;

	std::vector<PF::Node> nodeList;

	float cameraOffsetX;
	float cameraOffsetY;
	int	  playerOffset = 300;
};