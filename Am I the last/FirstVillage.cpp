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
	this->try_to_end_state(sf::Keyboard::Escape);
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
