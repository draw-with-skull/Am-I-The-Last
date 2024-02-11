#pragma once
#include<stack>

class State;
class StateManager
{
public:
	enum STATE_NAME
	{
		STARTING_CITY,
		FIRST_VILLAGE
	};
public:
	StateManager();
	void add_state(State* state);
	void revome_state();
	void switch_state(State* state);
	void save_current_state(STATE_NAME name);
	State* get_state();
	virtual ~StateManager();
private:
	std::stack<State*> *states;
	State* state_to_change= nullptr;
};
