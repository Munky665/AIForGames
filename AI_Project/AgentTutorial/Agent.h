#pragma once
#include "IAgent.h"
#include "Node.h"

class Agent
{

public:
	Agent(glm::vec2 pos, float maxVel, float maxForce);
	Agent(glm::vec2 pos);
	virtual ~Agent();
	//update the agent and its behaviours
	void Update(float deltaTime, std::vector<Node> node) ;
	//draw the agent
	void Draw(aie::Renderer2D* renderer) ;
	//add behaviour to the agent
	void AddBehaviour(IBehaviour* behaviour) ;
	Rect* GetCollider() ;
	//Movement functions
	void SetPosition(glm::vec2 position) ;
	glm::vec2 GetPosition() const ;
	void SetVelocity(glm::vec2 velocity) ;
	glm::vec2 GetVelocity() ;
	void AddForce(glm::vec2 force, float deltaTime) ;
	void SetSprite(const char* string) ;
	void SetRotation(float num) ;
	glm::vec2 CurrentTile() ;
	void SetCurrentTile(int x, int y) ;

private:
	std::vector<IBehaviour*> m_BehaviourList;
	glm::vec2 m_Position{0,0};
	glm::vec2 m_Velocity;
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

