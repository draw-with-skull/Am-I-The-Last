#include "BuildingSingleInterior.h"

BuildingSingleInterior::BuildingSingleInterior(const std::string textur_name, sf::RenderWindow* target):Building(textur_name,target)
{
}

void BuildingSingleInterior::update(const float& dt,sf::Vector2f position)
{
	this->update_view(position);
	this->window->setView(this->view);
}

void BuildingSingleInterior::render(const sf::RenderTarget* target)
{
	this->window->draw(*this->interior);
}


