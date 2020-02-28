#pragma once
#include <glm/glm.hpp>
#include "Rect.h"

static bool CheckCollision(Rect* one, Rect* two, glm::vec2 vel)
{
	vel = glm::normalize(vel);
	if (one->x + one->width  / 2 + vel.x < two->x - two->width  / 2) 
		return 0; //right
	if (one->x - one->width  / 2 + vel.x > two->x + two->width  / 2) 
		return 0; //left
	if (one->y + one->height / 2 + vel.y < two->y - two->height / 2) 
		return 0; //top
	if (one->y - one->height / 2 + vel.y > two->y + two->height / 2) 
		return 0; //bottom
	return 1;
}
static int CheckCollision(Rect* one, Rect* two)
{
	if (one->x + one->width  / 2 - two->width  / 2) return 0; //right
	if (one->x - one->width  / 2 + two->width  / 2) return 0; //left
	if (one->y + one->height / 2 - two->height / 2) return 0; //top
	if (one->y - one->height / 2 + two->height / 2) return 0; //bottom
	return 1;
}