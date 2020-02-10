#pragma once
#include <stack>
#include <vector>
#include "Behaviour.h"

class State;
class Transition;
class Condition;
class Agent;
class Node;

	enum ebehaviourResult
	{
		SUCCESS,
		FAILURE
	};

	class FSM : public IBehaviour{
	public:
		FSM();
		virtual ~FSM();
		virtual glm::vec2 Update(Agent* a, float deltaTime, std::vector<Node> node) override;
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
