#include "FirstVillage.h"

FirstVillage::FirstVillage(sf::RenderWindow* window, StateManager* manager)
	:State(window,manager)
{
}

void FirstVillage::update(const float& dt)
{
	//printf("\nvillage");
	this->update_input(dt);
}

void FirstVillage::update_input(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}

void FirstVillage::render(sf::RenderTarget* target)
{
}

void FirstVillage::end_state()
{
}

void FirstVillage::import_assets()
{
}
