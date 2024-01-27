#include "Player_top.h"

void Player_top::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}

void Player_top::update( sf::Vector2f mouse_position,const float &dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		this->calculate_diraction(mouse_position);
		this->is_moveing = true;
	}
	if (!this->sprite.getGlobalBounds().contains(destination))
	{
		sprite.move(move*dt);
		position = sprite.getPosition();
		this->calculate_diraction(destination);
	}
	else
		this->is_moveing = false;

		
}

void Player_top::calculate_diraction(const sf::Vector2f mouse_position)
{
	float delta_x = mouse_position.x - sprite.getPosition().x;
	float delta_y = mouse_position.y - sprite.getPosition().y;
	destination.x = mouse_position.x;
	destination.y = mouse_position.y;
	float angle = atan2(delta_x, delta_y)*180.0f/PI;
	move.x = sin(angle) * 70;
	move.y = cos(angle) * 70;
}

void Player_top::import_texture()
{
	this->texture = new sf::Texture;
	texture->loadFromFile("Textures/Entity/player_icon.png");
	sprite.setTexture(*texture);
	sprite.setOrigin(16, 16);
}

Player_top::Player_top()
{
	this->import_texture();
}

Player_top::~Player_top()
{
	delete this->texture;
}
