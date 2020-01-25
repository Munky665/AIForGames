#include "FSMTransition.h"


	Transition::Transition(State* target, Condition* c) : m_target_state(target), m_condition(c)
	{
	}
	State* Transition::GetTargetState() 
	{ 
		return m_target_state; 
	}
	bool Transition::HasTriggered(Agent* a) 
	{
		return m_condition->Test(a); 
	}
