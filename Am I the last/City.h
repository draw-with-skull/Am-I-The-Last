#pragma once
#include "State.h"
#include "Building.h"
#include "Player_top.h"
//#include <fstream>
class City
{
public://funtions
	void render_city(sf::RenderTarget* target);
	void update_city(sf::Vector2f mouse_position,const float &dt, sf::RenderTarget *window);
	void set_view(sf::RenderTarget *target);
public://variables
	bool checked;
private://funtions
	void init_keybinds();
	void import_city_data();
	void update_view(sf::RenderTarget *target);
	
private://variables
	sf::Sprite city_sprite;
	sf::Texture *city_texture;
	sf::View city_view;
	sf::Vector2f position;

	std::vector<Building> building;
	
	Player_top player;

	unsigned int buildings_count;
	
public://constructor destructor
	City();
	virtual ~City();
};

