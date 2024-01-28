#include "StateManager.h"
#include "State.h"
#include "Main_meniu_state.h"
StateManager::StateManager()
{
	this->states = new std::stack<State*>;
}

void StateManager::add_state(State *state)
{
	//this->states->push(new Main_meniu_state(nullptr, nullptr));
	this->states->push(state);
}

void StateManager::revome_state()
{
	if (this->states->size() > 1) {
		delete this->states->top();
		this->states->pop();
	}
}

void StateManager::switch_state(State *state)
{
	if (this->states->size() > 0) {
		delete this->states->top();
		this->states->pop();
		this->states->push(state);
	}
}

  State* StateManager::get_state()
{
		//remove state
	if (this->states->top()->quit) {
		this->revome_state();
	}
	if (!this->states->empty()) {
		return this->states->top();
	}
	return nullptr;
}

StateManager::~StateManager()
{
	while (!this->states->empty()) {
		delete this->states->top();
		this->states->pop();
	}
}
