#include "Collider.h"
#include "Agent.h"
#include "Tile.h"
#include <MathLib.h>
#include "Rect.h"



Collider::Collider()
{
}

int Collider::CheckCollision(Rect* one, Rect* two, Vector2 vel)
{
	vel = vel.normalised();
	if (one->x + one->width / 2  + vel.x < two->x - two->width / 2) return 0;
	if (one->x - one->width / 2  + vel.x > two->x + two->width / 2) return 0;
	if (one->y + one->height / 2 + vel.y < two->y - two->height / 2) return 0;
	if (one->y - one->height / 2 + vel.y > two->y + two->height / 2) return 0;
	return 1;
}


Collider::~Collider()
{
	 
}

