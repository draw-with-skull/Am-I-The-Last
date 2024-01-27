#pragma once
#include<stack>
class State;
class StateManager
{
public:
	StateManager();
	void add_state(State* state);
	void revome_state();
	void switch_state(State* state);
	 State* get_state();
	virtual ~StateManager();
private:
	std::stack<State*> *states;
};
