#include "FSMCondition.h"
#include "Agent.h"

	Condition::Condition()
	{

	}
	
	Condition::~Condition()
	{

	}

	CheckRange::CheckRange(const Agent* t, float range) : target{ t }, somevalue{ range }
	{

	}

	bool CheckRange::Test(Agent* a) const {
		Vector2 vec1 = a->GetPosition();
		Vector2 vec2 = target->GetPosition();
		Vector2 dist(0, 0);
		if (dist.distance(vec1, vec2) <= somevalue)
			return true;
		else
			return false;
	}
