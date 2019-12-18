#pragma once
#include <Renderer2D.h>
#include <Texture.h>
#include <string>
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
};

