#include "SearchBehaviour.h"
#include "SearchBox.h"
#include "Agent.h"
#include "Player.h"


SearchBehaviour::SearchBehaviour( Player* p )
{
	m_player = p;
}


SearchBehaviour::~SearchBehaviour()
{
}

void SearchBehaviour::MakeDecision(Agent * a, float deltaTime, MapLoader * map)
{
	//move search boxes up/down/left/right
	if (a->GetChase() == false) {
		for (int i = 0; i < 4; ++i)
		{
			switch (i)
			{
				//move box right
			case 0:
				a->GetSearchBoxes()[i]->SetVeloity(glm::vec2(1.0f, 0) * 100.0f * deltaTime, m_player);
				break;
				//move box left
			case 1:
				a->GetSearchBoxes()[i]->SetVeloity(glm::vec2(-1.0f, 0) * 100.0f * deltaTime, m_player);

				break;
				//move box up
			case 2:
				a->GetSearchBoxes()[i]->SetVeloity(glm::vec2(0, 1.0f) * 100.0f * deltaTime, m_player);
				break;
				//move box right
			case 3:
				a->GetSearchBoxes()[i]->SetVeloity(glm::vec2(0, -1.0f) * 100.0f * deltaTime, m_player);
				break;
			}
		}
	}
	if (m_c->Test(a) == false) 
	{
		m_b->MakeDecision(a, deltaTime, map);
	}

}
