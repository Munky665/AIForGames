#include "Condition.h"
#include "Agent.h"
#include "Node.h"
#include "SearchBox.h"
#include "Player.h"

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
	if (a->GetChase() == false) {
		glm::vec2 vec1 = a->GetPosition();
		glm::vec2 vec2 = a->GetTarget()->position;
		float dist = glm::distance(vec1, vec2);
		if (dist <= somevalue)
		{
			a->AtPathEnd(true);
			return false; //search
		}
		else
		{
			return true; //continue patroling/chasing
		}
	}
	else
		return false;
}

UseSearch::UseSearch()
{
}

bool UseSearch::Test(Agent * a) const
{
	if (a->GetChase() != true) {
		for (SearchBox* b : a->GetSearchBoxes())
		{
			if (b->HasCollided() == true)
			{
				a->SetChase(true);

				break;
			}
		}
	}
	if (a->GetSearchTime() > 5)
	{
		return true; //return to patrol
	}
	else if (a->GetChase() == true)
	{
		return false; //seek player
	}
}

Chase::Chase(Player* p)
{
	m_player = p;
}

bool Chase::Test(Agent * a) const
{
	auto magnitude = m_player->GetPosition() - a->GetPosition();
	if (glm::length(magnitude) < 10)
	{
		a->SetChase(true);
	}
	return a->GetChase();
}
