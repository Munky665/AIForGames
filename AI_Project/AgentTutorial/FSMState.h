#pragma once
#include "State.h"

class IdleState :
	public State
{
public:
	IdleState();
	virtual void Init(Agent* a);
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
public:
	float somevalue;
	const Agent* target;
	WithinRange(const Agent* t, float range);
	virtual bool Test(Agent* a) const override;

};

class ConditionalAND : public Condition
{
protected:
	const Condition* a;
	const Condition* b;
public:
	ConditionalAND(const Condition* ca, const Condition* cb);
	bool Test(Agent* ag) const override;
};

class ConditionalNOT : public Condition
{
protected:
	const Condition* a;
public:
	ConditionalNOT(const Condition* ca);
	bool Test(Agent* ag) const override;
};