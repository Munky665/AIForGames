#include "Condition.h"
#include "Agent.h"
#include "Node.h"
#include "SearchBox.h"

Condition::Condition()
{

}

Condition::~Condition()
{

}

CheckRange::CheckRange(const Node* t, float range) : target{ t }, somevalue{ range }
{

}

bool CheckRange::Test(Agent* a) const {
	glm::vec2 vec1 = a->GetPosition();
	glm::vec2 vec2 = a->GetTarget()->position;
	float dist = glm::distance(vec1, vec2);
	if (dist <= 2.0f)
	{
		a->AtPathEnd(true);
		return false; //node b
	}
	else
	{
		return true; //node a
	}
}

UseSearch::UseSearch()
{
}

bool UseSearch::Test(Agent * a) const
{
	int count = 0;
	for (SearchBox* b : a->GetSearchBoxes())
	{
		if (b->HasCollided() == true)
		{
			count++;
		}
	}
	if (a->GetSearchTime() > 5)
	{
		return true; //node a
	}
	else if (count != a->GetSearchBoxes().size())
	{
		return false; //node b
	}

}
