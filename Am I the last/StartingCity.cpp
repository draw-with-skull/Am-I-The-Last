#include "StartingCity.h"

StartingCity::StartingCity(sf::RenderWindow* window, std::stack<State*>* states):State(window,states)
{
	printf("\n StartingCity");
	this->import_assets();
	this->view.setSize(this->view_size);
}

StartingCity::~StartingCity()
{
}

void StartingCity::update(const float& dt)
{
	update_input(dt);
	update_view();
	//printf("\nupdate");

}

void StartingCity::update_input(const float& dt)
{
	this->update_mouse_position();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}

void StartingCity::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->setView(this->view);

	target->draw(this->map);
	//printf("\nrender");
}

void StartingCity::end_state()
{
	//save stuff
}

void StartingCity::import_assets()
{
	this->map_texture = new sf::Texture;
	this->map_texture->loadFromFile("Textures/Maps/1.png");
	this->map.setTexture(*this->map_texture);
}

void StartingCity::update_view()
{

	sf::Vector2f view_center = mouse_position_view;
	sf::Vector2f map_size = sf::Vector2f(map_texture->getSize());

	//set bounds on x
	if (view_center.x < this->view_size.x / 2)//left
		view_center.x = this->view_size.x/2;
	if (view_center.x > (map_size.x - (this->view_size.x / 2)))//right
		view_center.x= map_size.x-view_size.x/2;

	//set bounds on y
	if (view_center.y < this->view_size.y / 2)//top
		view_center.y = this->view_size.y / 2;
	if(view_center.y>(map_size.y-(this->view_size.y/2)))//bottom
		view_center.y = map_size.y-view_size.y/2;


	this->view.setCenter(view_center);
	
}
