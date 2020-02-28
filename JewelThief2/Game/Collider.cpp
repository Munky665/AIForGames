#include <glm/glm.hpp>
#include "Rect.h"

static bool CheckCollision(Rect* one, Rect* two, glm::vec2 vel)
{
	if (one->x < two->x + two->width &&
		one->x + one->width > two->x &&
		one->y < two->y + two->height &&
		one->y + one->height > two->y) {
		return true;
	}
	return false;
}
