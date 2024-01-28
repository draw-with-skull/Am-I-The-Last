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
		sprite.move(move*dt*speed);
		position = sprite.getPosition();
		//this->calculate_diraction(destination);
	}
	else
		this->is_moveing = false;

		
}

void Player_top::set_position(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void Player_top::calculate_diraction(const sf::Vector2f mouse_position)
{
	destination = mouse_position;
	move =  destination- sprite.getPosition();
	move = Math::Normilize(move);
	//adjust destination based on direction
	sf::Vector2f adjustmet = move * (sf::Vector2f(texture->getSize()) / 2.f).x;//move .5 of the texture
	destination += adjustmet;


}

void Player_top::import_texture()
{
	this->texture = new sf::Texture;
	texture->loadFromFile("Textures/Entity/player_icon.png");
	sprite.setTexture(*texture);
	sprite.setOrigin(sf::Vector2f(texture->getSize())/2.f);//centre of the texture
}

Player_top::Player_top()
{
	this->import_texture();
}

Player_top::~Player_top()
{
	delete this->texture;
}
