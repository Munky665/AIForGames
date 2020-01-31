#pragma once
#include <vector>
#include <MathLib.h>
#include "Renderer2D.h"
#include "Level.h"

class IBehaviour;
class Rect;

class IAgent
{
public:
	IAgent() {};
	virtual ~IAgent() {};

	//update the agent and its behaviours
	virtual void Update(float deltaTime, Level currentMap) = 0;
	//draw the agent
	virtual void Draw(aie::Renderer2D* renderer) = 0;
	//add behaviour to the agent
	virtual void AddBehaviour(IBehaviour* behaviour) = 0;
	
	virtual void AddForce(Vector2 force, float deltaTime) = 0;

	virtual Rect* GetCollider() = 0;
	//Movement functions
	virtual void SetPosition(Vector2 position) = 0;
	virtual void SetVelocity(Vector2 velocity) = 0;
	virtual void SetSprite(const char* string) = 0;
	virtual void SetRotation(float num) = 0;
	virtual void SetCurrentTile(int x, int y) = 0;

	virtual Vector2 GetPosition() const = 0;
	virtual Vector2 CurrentTile() = 0;
	virtual Vector2 GetVelocity() = 0;
};

