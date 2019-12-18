#pragma once
#include <Renderer2D.h>
#include <Texture.h>
#include <string>

class Vector2;

class Tile
{
private:
	aie::Texture* m_tile;
	int PosX, PosY;
	bool walkable;
	int id;
public:
	Tile(int texture, int x, int y, bool walkable);
	Tile(aie::Texture * tile);
	void Draw( aie::Renderer2D* renderer);
	~Tile();
	aie::Texture * GetTexture(int texture);
	aie::Texture * GetTexture();
	int GetId();
	Vector2 GetPosition();
	void SetPosition(int x, int y);
};

