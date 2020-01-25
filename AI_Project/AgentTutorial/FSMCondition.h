#pragma once

class Agent;


	class Condition {
	public:
		Condition();
		virtual ~Condition();
		virtual bool Test(Agent* a) const = 0;
	};

	class CheckRange : public Condition
	{
		float somevalue;
		const Agent* target;
		CheckRange(const Agent* t, float range);
		virtual bool Test(Agent* a) const override;
	
	};
