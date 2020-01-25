#include "FSMState.h"


IdleState::IdleState()
{
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
	a->SetVelocity(Vector2());
	Vector2 v = v.normalise(m_target->GetPosition() - a->GetPosition()) * m_speed;
	a->SetVelocity(v);
}

WithinRange::WithinRange(const Agent* t, float range) : target{ t }, somevalue{ range }
{

}

bool WithinRange::Test(Agent* a) const {
	Vector2 vec1 = a->GetPosition();
	Vector2 vec2 = target->GetPosition();
	Vector2 dist(0, 0);
	if (dist.distance(vec1, vec2) <= somevalue)
		return true;
	else
		return false;
}
