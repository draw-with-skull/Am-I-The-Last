#include "Building.h"


void Building::update(const float& dt)
{
}

void Building::update_input(const float& dt)
{
}

void Building::render(sf::RenderTarget* target)
{
}

void Building::end_state()
{
}

void Building::import_assets()
{
}

void Building::import_data(std::string file_name)
{

}

void Building::get_type(INTERIOR type)
{
}

Building::Building(INTERIOR type, std::string data_file_name, sf::RenderWindow* window, StateManager* manager)
	:State(window,manager)
{
	this->import_assets();
	this->import_data(data_file_name);
	this->get_type(type);

}

Building::~Building()
{
}
