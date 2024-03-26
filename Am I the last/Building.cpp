#include "Building.h"

Building::Building(const std::string textur_name, sf::RenderWindow *target)
{
	this->window = target;
	this->interior_texture = AssetImporter::get_texture(AssetImporter::BUILDING, textur_name);
	this->interior = new sf::Sprite();
	this->interior->setTexture(*this->interior_texture);
}
Building::~Building() {
	delete this->interior;
	delete this->interior_texture;
}
void Building::update_view(const sf::Vector2f position) 
{
	sf::Vector2f view_center = position;
	sf::Vector2f map_size = sf::Vector2f(this->interior_texture->getSize());

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
