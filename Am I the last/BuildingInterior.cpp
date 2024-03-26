#include "BuildingInterior.h"

BuildingInterior::BuildingInterior(INTERIOR type, sf::RenderWindow* window, StateManager* manager)
	:State(window, manager)
{
	this->type = type;
	this->import_assets();
}

BuildingInterior::~BuildingInterior()
{

}

sf::Vector2f BuildingInterior::get_position()
{
	return sf::Vector2f();
}

void BuildingInterior::update(const float& dt)
{
	this->try_to_end_state(sf::Keyboard::Escape);
	//this->update_input(dt);
	this->building->update(dt, this->player.get_position());
	this->player.update({ 0,0 }, dt);
}

void BuildingInterior::update_input(const float& dt)
{
}

void BuildingInterior::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	this->building->render(this->window);
	this->player.render(target);
}

void BuildingInterior::end_state()
{
}

void BuildingInterior::import_assets()
{
	switch (this->type) {
	case HOUSE_0: {this->building = new BuildingSingleInterior("house_0",this->window); }break;
	case HOUSE_1: {}break;
	case HOUSE_2: {}break;
	case HOUSE_3: {}break;
	case HOUSE_4: {}break;
	case HOUSE_5: {}break;
	case HOUSE_6: {}break;
	case HOUSE_7: {}break;
	case HOUSE_8: {}break;
	case HOUSE_9: {}break;

	default: {/*create a default building for debuging*/}break;
	}
}



