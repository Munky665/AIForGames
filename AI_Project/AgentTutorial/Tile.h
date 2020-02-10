#pragma once
#include <Renderer2D.h>
#include <Texture.h>
#include <string>
#include <glm/glm.hpp>
#include "Rect.h"
class Tile
{
private:
	aie::Texture* m_tile;
	float PosX, PosY;
	bool walkable;
	glm::vec2 position;
	int id;
public:
	Tile(int texture, float x, float y);
	Tile(aie::Texture * tile);
	void Draw( aie::Renderer2D* renderer);
	~Tile();
	aie::Texture * GetTexture(int texture);
	aie::Texture * GetTexture();
	int GetId();
	glm::vec2 GetPosition();
	void SetPosition(float x, float y);
	bool IsWalkable();
	void SetWalkable(bool walkable);
	Rect* collider;
};

