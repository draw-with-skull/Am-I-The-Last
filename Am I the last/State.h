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
	virtual void check_for_quit();
	//plain
public://variables
	bool quit;
	std::stack<State*>*states;
private://functions
protected:
	virtual void init_keybinds() = 0;
private://variables

protected:
	sf::RenderWindow *window;
	std::map<std::string, int>*supported_keys;
	std::map<std::string, int> keybinds;
	
	//mouse pozition and stuff
	sf::Vector2i mouse_position_screen;
	sf::Vector2i mouse_position_window;
	sf::Vector2f mouse_position_view;

public://constructor destructor
	State(sf::RenderWindow *window, std::map<std::string, int>* supported_keys,std::stack<State*>*states);
	~State();
};

