#pragma once
class Agent;
class Node;

class Condition {
public:
	Condition();
	virtual ~Condition();
	virtual bool Test(Agent* a) const = 0;
};

class CheckRange : public Condition
{
	float somevalue;
	const Node* target;
public:
	CheckRange( const Node* t, float range);
	virtual bool Test(Agent* a) const override;

};

class UseSearch : public Condition
{
public:
	UseSearch();
	virtual bool Test(Agent* a) const override;
};

