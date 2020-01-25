#pragma once
#include <stack>
#include <vector>
#include "Behaviour.h"

class State;
class Transition;
class Condition;
class Agent;

	enum ebehaviourResult
	{
		SUCCESS,
		FAILURE
	};

	class FSM : public IBehaviour{
	public:
		FSM();
		virtual ~FSM();
		virtual Vector2 Update(Agent* a, float deltaTime, Level currentMap) override;
		virtual ebehaviourResult execute(Agent* gameObject, float deltaTime);
		State* AddState(State* state);
		Transition* AddTransition(Transition* transition);
		Condition* AddCondition(Condition* condition);
		void SetCurrentState(State* state);

	protected:
		State* m_current_state;
		//std::stack<State*>m_statestack;
		std::vector<State*>m_states;
		std::vector<Transition*>m_transitions;
		std::vector<Condition*>m_conditions;
	};
