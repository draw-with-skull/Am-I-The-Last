#pragma once
#include "Main_meniu_state.h"
class Game {

public://functions
	//Delta time stuff
	void update_dt();
	//Game loop
	void update_events_sfml();
	void update();
	void render();
	void run();


	void end_application();
	//Window
	void create_window();
public://variables
	sf::Vector2u window_scale;
private://functions
	//States
		void init_State();
	//others
	//Window
		void init_window();
		void save_window_settings();
	
	private://variables
	//States 
		std::stack<State*> state;
	//Delta time
		float dt;
		sf::Clock dt_Clock;
	//Window
		sf::RenderWindow *window;
		sf::Event sf_event;
		short frame_rate;
public://constructors destructors
	Game();
	virtual ~Game();
};