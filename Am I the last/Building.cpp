#include "Building.h"


void Building::update(const float& dt)
{
	this->try_to_end_state(sf::Keyboard::Escape);
	this->update_view();
	this->update_input(dt);
	this->player.update({ 0,0 }, dt);
}

void Building::update_input(const float& dt)
{
}

void Building::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->setView(this->view);
	target->draw(*this->interior);
	this->player.render(target);
}

void Building::end_state()
{
}

void Building::import_assets()
{
	//this->interior_texture = new sf::Texture();
	this->interior_texture = AssetImporter::get_texture(AssetImporter::BUILDING,this->get_type());
	this->interior = new sf::Sprite();
	this->interior->setTexture(*this->interior_texture);
}

void Building::import_data()
{

}

void Building::update_view()
{
	sf::Vector2f view_center = sf::Vector2f(100,1000);
	sf::Vector2f map_size = sf::Vector2f(interior_texture->getSize());

	//set bounds on x
	if (view_center.x < this->view_size.x / 2)//left
		view_center.x = this->view_size.x / 2;
	if (view_center.x > (map_size.x - (this->view_size.x / 2)))//right
		view_center.x = map_size.x - view_size.x / 2;

	//set bounds on y
	if (view_center.y < this->view_size.y / 2)//top
		view_center.y = this->view_size.y / 2;
	if (view_center.y > (map_size.y - (this->view_size.y / 2)))//bottom
		view_center.y = map_size.y - view_size.y / 2;


	this->view.setCenter(view_center);
}

std::string Building::get_type()
{
	std::string name="";

	switch (this->type) {
		case HOUSE_0: {name = "house_0"; }break;
		case HOUSE_1: {name = "house_1"; }break;
		case HOUSE_2: {name = "house_2"; }break;
		case HOUSE_3: {name = "house_3"; }break;
		case HOUSE_4: {name = "house_4"; }break;
		case HOUSE_5: {name = "house_5"; }break;
		case HOUSE_6: {name = "house_6"; }break;
		case HOUSE_7: {name = "house_7"; }break;
		case HOUSE_8: {name = "house_8"; }break;
		case HOUSE_9: {name = "house_9"; }break;

		default: {name = ""; }break;
	}

	return name;
}



Building::Building(INTERIOR type, sf::RenderWindow* window, StateManager* manager)
	:State(window,manager)
{
	this->type = type;
	this->view.setSize(this->view_size);
	this->import_assets();
	this->import_data();
}

Building::~Building()
{
	delete this->interior_texture;
	delete this->interior;
}
