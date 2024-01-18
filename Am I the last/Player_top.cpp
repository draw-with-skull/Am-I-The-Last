#include "Player_top.h"



void Player_top::render_player(sf::RenderTarget * target)
{
	target->draw(this->player_sprite);
}

void Player_top::update_player( sf::Vector2f mouse_position,const float &dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		this->calculate_diraction(mouse_position);
		this->is_moveing = true;
	}
	if (!this->player_sprite.getGlobalBounds().contains(destination))
	{
		player_sprite.move(move*dt);
		player_position = player_sprite.getPosition();
		this->calculate_diraction(destination);
	}
	else
		this->is_moveing = false;

		
}

void Player_top::calculate_diraction(const sf::Vector2f mouse_position)
{
	float delta_x = mouse_position.x - player_sprite.getPosition().x;
	float delta_y = mouse_position.y - player_sprite.getPosition().y;
	destination.x = mouse_position.x;
	destination.y = mouse_position.y;
	float angle = atan2(delta_x, delta_y)*180.0f/PI;
	move.x = sin(angle) * 70;
	move.y = cos(angle) * 70;
}

void Player_top::import_texture()
{
	this->player_texture = new sf::Texture;
	player_texture->loadFromFile("Textures/Entity/player_icon.png");
	player_sprite.setTexture(*player_texture);
	player_sprite.setOrigin(16, 16);
}

Player_top::Player_top()
{
	this->import_texture();
}

Player_top::~Player_top()
{
	delete this->player_texture;
}
