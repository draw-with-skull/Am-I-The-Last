#include "Button.h"

void Button::render_button(sf::RenderTarget * target)
{
	target->draw(this->button_sprite);
}

void Button::update_button(const sf::Vector2f mouse_position)
{
	//clear some day
	this->button_state = button_idle;
	//hover stuff
	if (this->button_shape.getGlobalBounds().contains(mouse_position)) {
		this->button_state = button_hover;
		//pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && is_released)
		{
			is_released = false;
			this->button_state = button_pressed;
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !is_released)
			is_released = true;

	}
		
	switch (this->button_state)
	{
	case button_idle:
		button_sprite.setTextureRect(sf::IntRect(0, 0, this->width, this->height));
		break;
	case button_hover:
		button_sprite.setTextureRect(sf::IntRect(0,this->height, this->width, this->height));
		break;
	case button_pressed:
		button_sprite.setTextureRect(sf::IntRect(0, this->height*2, this->width, this->height));
		break;
	default:
		this->button_shape.setFillColor(sf::Color::Red);
		break;
	}
}

const bool Button::is_pressed() const
{		
	if (this->button_state == button_pressed)
		return true;
	else
		return false;
}

void Button::Import_button_texture(std::string file_name)
{
	file_name.insert(0, "Textures/Buttons/");
	this->button_texture = new sf::Texture;
	this->button_texture->loadFromFile(file_name);
}


Button::Button(unsigned short x, unsigned short y, unsigned short width, unsigned short height, std::string file_name)
{
	this->button_state = button_idle;
	this->width = width;
	this->height = height;
	this->Import_button_texture(file_name);
	this->button_shape.setPosition(sf::Vector2f(x-width/2, y));
	this->button_shape.setSize(sf::Vector2f(width, height));
	this->button_sprite.setTexture(*button_texture);
	this->button_sprite.setPosition(sf::Vector2f(x-width/2, y));
}


Button::~Button()
{
	delete this->button_texture;
}
