#pragma once
#include "FSMCondition.h"


	class State;

	class Transition {
	public:
		Transition(State* target, Condition* c);
		State* GetTargetState();
		bool HasTriggered(Agent* a);
	private:
		State* m_target_state;
		Condition* m_condition;
	};
