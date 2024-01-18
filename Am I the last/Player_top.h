#pragma once
#include<SFML/Graphics.hpp>
#define PI 3.14
class Player_top
{
public://functions
	void render_player(sf::RenderTarget *target);
	void update_player( sf::Vector2f mouse_position,const float &dt);

public://variables
	sf::Vector2f player_position;
	sf::Sprite player_sprite;
	bool is_moveing;
private://funtion
	void calculate_diraction(const sf::Vector2f mouse_position);
	void import_texture();
private://variables
	sf::Texture *player_texture;
	
	sf::Vector2f destination;
	sf::Vector2f move;
public://constructor destructor
	Player_top();
	virtual ~Player_top();
};


