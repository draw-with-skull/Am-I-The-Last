#include "StartingCity.h"
#include "FirstVillage.h"
StartingCity::StartingCity(sf::RenderWindow* window,StateManager* manager ):State(window,manager)
{
	printf("\n StartingCity");
	this->import_assets();
	this->view.setSize(this->view_size);
	this->player = new Player_top();
	this->import_data();
	this->change_scene_to_first_village = sf::FloatRect(0,190,50,70);
}

inline StartingCity::~StartingCity()
{
	delete this->player;
	delete this->map_texture;
}

void StartingCity::update(const float& dt)
{
	update_input(dt);
	update_view();
	this->player->update(this->mouse_position_view,dt);
	if (this->quit)this->end_state();

}

void StartingCity::update_input(const float& dt)
{
	this->update_mouse_position();

	this->try_to_end_state(sf::Keyboard::Escape);
	this->try_to_change_state();
}

void StartingCity::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->setView(this->view);

	target->draw(this->map);
	player->render(target);
	//printf("\nrender");
}

void StartingCity::end_state()
{
	this->view.setSize(this->view_size);
	this->view.setCenter(this->view_size / 2.f);
	this->window->setView(this->view);
	this->save_data();
}

void StartingCity::import_assets()
{
	this->map_texture = new sf::Texture;
	this->map_texture->loadFromFile("Textures/Maps/1.png");
	this->map.setTexture(*this->map_texture);
}

void StartingCity::update_view()
{

	sf::Vector2f view_center = this->player->position;
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

void StartingCity::import_data()
{
	//import player position
	std::ifstream city_data;
	sf::Vector2f player_position;
	city_data.open("City/StartingCity/data.txt");
	city_data >> player_position.x;
	city_data >> player_position.y;
	city_data.close();
	//set Player Position
	this->player->set_position(player_position) ;
}

void StartingCity::save_data()
{
	//save player position;
	std::ofstream city_data;
	city_data.open("City/StartingCity/data.txt");
	city_data << this->player->position.x<<" ";
	city_data << this->player->position.y;
	city_data.close();
}

void StartingCity::try_to_change_state()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		this->change_state = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E) && this->change_state)
		if (this->change_scene_to_first_village.contains(this->player->position)) {
			this->manager->switch_state(new FirstVillage(this->window, this->manager));
		}
}
