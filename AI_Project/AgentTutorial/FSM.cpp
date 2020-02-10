#include "FSM.h"
#include "State.h"
#include "FSMTransition.h"
#include "FSMCondition.h"

FSM::FSM() : m_current_state(nullptr)
	{

	}

	FSM::~FSM()
	{

	}

	glm::vec2 FSM::Update(Agent * a, float deltaTime, std::vector<Node> node)
	{
		execute(a, deltaTime);
		return glm::vec2(0, 0);
	}

	ebehaviourResult FSM::execute(Agent * gameObject, float deltaTime)
	{
		if (m_current_state) {
			Transition* transition = m_current_state->GetTriggeredTransition(gameObject);
			if (transition)
			{
				m_current_state->Exit(gameObject);
				m_current_state = transition->GetTargetState();
				m_current_state->Init(gameObject);
			}
			m_current_state->Update(gameObject, deltaTime);
			return ebehaviourResult::SUCCESS;
		}
		return ebehaviourResult::FAILURE;
	}

	State* FSM::AddState(State* state) {
		m_states.push_back(state);
		return state;
	}

	Transition* FSM::AddTransition(Transition* transition) {
		m_transitions.push_back(transition);
		return transition;
	}

	Condition* FSM::AddCondition(Condition* condition) {
		m_conditions.push_back(condition);
		return condition;
	}

	void FSM::SetCurrentState(State* state)
	{
		m_current_state = state;
	}


