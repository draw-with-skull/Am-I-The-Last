#pragma once

#include "Entity.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include "StateManager.h"
class StateManager;
class State
{
public://funtions
	virtual void update(const float& dt) = 0;
	virtual void update_input(const float& dt) = 0;
	virtual void update_mouse_position();
	virtual void render(sf::RenderTarget* target=nullptr) = 0;
	virtual void end_state() = 0;
	virtual void import_assets() = 0;
	virtual void check_for_quit();
public://variables
	bool quit;
	StateManager* manager;

protected:
	sf::RenderWindow *window;
	
	//mouse pozition and stuff
	sf::Vector2i mouse_position_screen;
	sf::Vector2i mouse_position_window;
	sf::Vector2f mouse_position_view;
	//ending state 
	void try_to_end_state(sf::Keyboard::Key key);
	
	bool try_to_quit;

public://constructor destructor
	State(sf::RenderWindow *window,StateManager *manager);
	~State();
};