#include <glm/glm.hpp>
#include "Rect.h"

static int CheckCollision(Rect* one, Rect* two, glm::vec2 vel)
{
	//vel = glm::normalize(vel);
	if (one->x + one->width  / 2 + vel.x < two->x - two->width  / 2) return 0;
	if (one->x - one->width  / 2 + vel.x > two->x + two->width  / 2) return 0;
	if (one->y + one->height / 2 + vel.y < two->y - two->height / 2) return 0;
	if (one->y - one->height / 2 + vel.y > two->y + two->height / 2) return 0;
	return 1;
}
