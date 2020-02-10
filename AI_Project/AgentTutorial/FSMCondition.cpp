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
		glm::vec2 vec1 = a->GetPosition();
		glm::vec2 vec2 = target->GetPosition();
		glm::vec2 dist(0, 0);
		if (glm::distance(vec1, vec2) <= somevalue)
			return true;
		else
			return false;
	}
