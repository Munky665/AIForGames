#include "FSMState.h"


IdleState::IdleState()
{
}

void IdleState::Init(Agent * a)
{
	a->SetVelocity(glm::vec2());
}

IdleState::~IdleState()
{
}

void IdleState::Update(Agent * a, float deltaTime)
{
}

AttackState::AttackState(Agent * target, float speed) : m_target(target), m_speed(speed)
{
}

AttackState::~AttackState()
{
}

void AttackState::Update(Agent * a, float deltaTime)
{
	a->SetVelocity(glm::vec2());
	glm::vec2 v = glm::normalize(m_target->GetPosition() - a->GetPosition()) * m_speed;
	a->SetVelocity(v);
}

WithinRange::WithinRange(const Agent* t, float range) : target{ t }, somevalue{ range }
{

}

bool WithinRange::Test(Agent* a) const {
	glm::vec2 vec1 = a->GetPosition();
	glm::vec2 vec2 = target->GetPosition();
	glm::vec2 dist(0, 0);
	if (glm::distance(vec1, vec2) <= somevalue)
		return true;
	else
		return false;
}

ConditionalAND::ConditionalAND(const Condition * ca, const Condition * cb)
	:a{ca}, b {cb}
{
}

bool ConditionalAND::Test(Agent * ag) const
{
	return a->Test(ag) || b->Test(ag);
}

ConditionalNOT::ConditionalNOT(const Condition * ca)
	: condition{ ca }
{
}

bool ConditionalNOT::Test(Agent * ag) const
{
	return !condition->Test(ag);
}
