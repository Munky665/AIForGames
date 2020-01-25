#pragma once
#include "Agent.h"
#include "FSMTransition.h"


	class State
	{
	public:
		State() {};
		~State()
		{
			for (auto t : m_transition)
			{
				//might have to delete transition later.
			}
		};

		virtual void Init(Agent*) {};
		virtual void Update(Agent*, float deltaTime) = 0;
		virtual void Exit(Agent*) {};

		void AddTrasition(Transition* t)
		{
			m_transition.push_back(t);
		}
		Transition* GetTriggeredTransition(Agent* a)
		{
			for (auto t : m_transition)
			{
				if (t->HasTriggered(a))
					return t;
			}
			return nullptr;
		}
	protected:
		std::vector<Transition*> m_transition;
	};

