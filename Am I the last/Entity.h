#pragma once
#include<SFML/Graphics.hpp>

class Entity
{
public://funtions
	void create_sprite(sf::Texture *texture);
	
	virtual void set_position(const float x, const float y);
	virtual void update(const float &dt);
	virtual void render(sf::RenderTarget *target);
	virtual void move(const float &dt, const float dir_x, const float dir_y);
public://variables

private://funtions 
	void init_variables();
private://variables
	protected:
		sf::Texture* entity_texture;
		sf::Sprite* entity_sprite;
		float movement_speed;

public://constructor destreuctor
	Entity();
	virtual ~Entity();
};

