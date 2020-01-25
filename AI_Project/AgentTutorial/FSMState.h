#pragma once
#include "State.h"

class IdleState :
	public State
{
public:
	IdleState();
	virtual ~IdleState();
	virtual void Update(Agent*, float);
};

class AttackState :
	public State
{
public:
	AttackState(Agent* target, float speed);
	virtual ~AttackState();
	virtual void Update(Agent*, float);

private:
	Agent* m_target;
	float m_speed;
};

class WithinRange : public Condition
{
	float somevalue;
	const Agent* target;
	WithinRange(const Agent* t, float range);
	virtual bool Test(Agent* a) const override;

};
