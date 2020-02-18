#pragma once
#include <glm/glm.hpp>
#include <Renderer2D.h>
#include <vector>
#include "IBehaviour.h"

class Rect;
class MapLoader;

class Player
{
public:

	Player(glm::vec2 p, float s, const char* sprite);
	~Player();

	void Update(float dT, MapLoader* map);
	void Draw(aie::Renderer2D* r);
	void AddBehaviour(IBehaviour* b);

	void colliderUpdate();

	//getters
	glm::vec2 GetPosition();
	float GetSpeed();
	Rect* GetCollider();


	//setters
	void SetPosition(glm::vec2 p);
	void SetVelocity(glm::vec2 p);
	void SetSprite(const char* sprite);
	void SetRotation(float r);



private:
	glm::vec2 m_position;
	glm::vec2 m_windowSize{ 1280.0f, 700.0f };
	std::vector<IBehaviour*> m_behaviourList;
	aie::Texture* m_sprite;

	Rect* m_collider;

	int m_windowBuffer = 58;

	float m_speed;
	float m_maxSpeed;
	float m_rotation;
	bool  m_triggeredCollider = false;
	
};
