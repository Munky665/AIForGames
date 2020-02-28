#pragma once
#include <glm/glm.hpp>
#include <Renderer2D.h>

class Rect;
class Player;

class SearchBox
{
public:
	SearchBox(glm::vec2 p, float s);
	~SearchBox();

	void Update(Player* p);

	//getters
	glm::vec2 GetPosition();
	bool HasCollided();

	//setters
	void SetPosition(glm::vec2 p);
	void SetVeloity(glm::vec2 pos ,Player* p);

	void Draw(aie::Renderer2D* r);

	glm::vec2 m_velocity;
private:
	
	glm::vec2 m_position;
	float m_alpha = 0;
	float m_size;
	bool m_collided = false;
	Rect* m_collider;
};

