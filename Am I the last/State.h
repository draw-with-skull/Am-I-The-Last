#pragma once

//#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
class State
{
public://funtions
	//conected to some sub classes
	virtual void update(const float& dt) = 0;
	virtual void update_input(const float& dt) = 0;
	virtual void update_mouse_position();
	virtual void render(sf::RenderTarget* target=nullptr) = 0;
	virtual void end_state() = 0;
	virtual void import_assets() = 0;
	virtual void check_for_quit();
public://variables
	bool quit;
	std::stack<State*>*states;


protected:
	sf::RenderWindow *window;
	
	//mouse pozition and stuff
	sf::Vector2i mouse_position_screen;
	sf::Vector2i mouse_position_window;
	sf::Vector2f mouse_position_view;

public://constructor destructor
	State(sf::RenderWindow *window,std::stack<State*>*states);
	~State();
};

