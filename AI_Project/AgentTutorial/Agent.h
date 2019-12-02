#pragma once

#include <vector>
#include <MathLib.h>
#include "Renderer2D.h"


class IBehaviour;

class Agent
{

public:
	Agent(Vector2 pos, Vector2 vel, float maxVel, float maxForce);
	Agent(Vector2 pos);
	virtual ~Agent();
	//update the agent and its behaviours
	void Update(float deltaTime);
	//draw the agent
	void Draw(aie::Renderer2D* renderer);
	//add behaviour to the agent
	void AddBehaviour(IBehaviour* behaviour);
	//Movement functions
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	void SetVelocity(Vector2 velocity);
	Vector2 GetVelocity();
	Vector2 GetForce();
	void SetColor(float r, float g, float b, float a);
	void AddForce(Vector2 force, float deltaTime);

private:
	std::vector<IBehaviour*> m_BehaviourList;
	Vector2 m_Force;
	Vector2 m_Position;
	Vector2 m_Velocity;
	Vector4 m_Color;
	float m_MaxVelocity;
	float m_MaxForce;
};

