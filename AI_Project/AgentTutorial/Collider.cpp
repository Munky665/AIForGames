#include "Collider.h"
#include "Agent.h"
#include "Tile.h"
#include <MathLib.h>


Collider::Collider()
{
}

bool Collider::CheckCollision(Agent* agent, Tile * tile)
{
	if (tile->GetId() != 4 || tile->GetId() != 5 || tile->GetId() != 1) {
		Vector2 col = (agent->GetPosition() + agent->GetVelocity()) - tile->GetPosition();
		float mag = col.magnitude();

		if (mag < 64)
			return true;
		else
			return false;
	}
	else
		return false;
}


Collider::~Collider()
{
	 
}

