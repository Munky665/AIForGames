#include "Application.h"
#pragma once
class GameLoop : public App::Application
{
public:
	GameLoop();
	virtual bool StartUp();
	virtual void ShutDown();
	virtual void Update(float deltaTime);
	virtual void Draw();
	~GameLoop();
};

