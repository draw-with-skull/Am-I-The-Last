#pragma once
#include<SFML/Graphics.hpp>
#include"Math.h"
class Player_top
{
public://functions
	void render(sf::RenderTarget *target);
	void update( sf::Vector2f mouse_position,const float &dt);
	void set_position(sf::Vector2f position);
public://variables
	sf::Vector2f position;
	sf::Sprite sprite;
	bool is_moveing;
private://funtion
	void calculate_diraction(const sf::Vector2f mouse_position);
	void import_texture();
private://variables
	sf::Texture *texture;
	
	sf::Vector2f destination;
	sf::Vector2f move;
	float speed = 100;
public://constructor destructor
	Player_top();
	virtual ~Player_top();
};


