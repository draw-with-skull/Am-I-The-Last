#pragma once
#include"State.h"
#include"Player_top.h"
#include"City.h"
#include<fstream>

class Game_state :
	public State
{
public://functions
	void render(sf::RenderTarget* target);
	void update(const float &dt);
	void update_input(const float &dt);
	void end_state();
public://variables
	std::string city_id;
private://funtions
	void init_data();
private://variables
	City city;
	sf::Vector2f window_size;
	sf::View view;
public://constructor destructor
	Game_state(sf::RenderWindow *window, std::stack<State*>*states);
	virtual ~Game_state();
};

