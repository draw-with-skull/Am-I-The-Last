#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class Window {
public://functions
	void create_window();
public://variables
	sf::RenderWindow *window;
private://functions
	void init_Window();
private://variables
	
	sf::Event sf_event;
	sf::Vector2u window_size;


public:
	Window();
	virtual ~Window();
};