#pragma once
#include "IAgent.h"


class Agent
{

public:
	Agent(Vector2 pos, float maxVel, float maxForce);
	Agent(Vector2 pos);
	virtual ~Agent();
	//update the agent and its behaviours
	void Update(float deltaTime, Level currentMap) ;
	//draw the agent
	void Draw(aie::Renderer2D* renderer) ;
	//add behaviour to the agent
	void AddBehaviour(IBehaviour* behaviour) ;
	Rect* GetCollider() ;
	//Movement functions
	void SetPosition(Vector2 position) ;
	Vector2 GetPosition() const ;
	void SetVelocity(Vector2 velocity) ;
	Vector2 GetVelocity() ;
	void AddForce(Vector2 force, float deltaTime) ;
	void SetSprite(const char* string) ;
	void SetRotation(float num) ;
	Vector2 CurrentTile() ;
	void SetCurrentTile(int x, int y) ;

private:
	std::vector<IBehaviour*> m_BehaviourList;
	Vector2 m_Position;
	Vector2 m_Velocity;
	Vector4 m_Color;
	aie::Texture* m_sprite;
	float m_MaxVelocity;
	float m_MaxForce;
	float m_Rotation;
	int m_CurrentX;
	int m_CurrentY;
	Rect* m_collider;
	bool collided = false;

};

