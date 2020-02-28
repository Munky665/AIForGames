#pragma once
#include <Renderer2D.h>
#include <glm/glm.hpp>

class Rect;

class Tile
{
public:
	Tile(int id, int h, int w, glm::vec2 pos);
	~Tile();

	void Draw(aie::Renderer2D* r);
	void SetSprite(int id);
	//getter
	bool IsWalkable();
	Rect* GetCollider();
	glm::vec2 GetPosition();
	int GetId();
	bool IsDoor();
	//setter
	void SetPosition(float x, float y);
private:

	glm::vec2 m_position;
	aie::Texture* m_sprite;
	Rect* m_collider;
	float m_id;
	float m_height;
	float m_width;
	bool m_door;
	bool m_walkable;
};

