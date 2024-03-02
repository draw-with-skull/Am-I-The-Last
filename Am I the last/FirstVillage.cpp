#include "FirstVillage.h"

FirstVillage::FirstVillage(sf::RenderWindow* window, StateManager* manager)
	:State(window,manager)
{
	printf("\n FirstVillage");
	this->import_assets();
	this->view.setSize(this->view_size);
	this->player = new Player_top();
	import_data();
	this->init_buildings();

	this->change_to_starting_city = sf::FloatRect(460,220,50,70);
}

FirstVillage::~FirstVillage()
{
}

void FirstVillage::update(const float& dt)
{
	this->update_input(dt);
	this->update_view(this->player->position);
	this->player->update(this->mouse_position_view, dt);
	//if player is moveing don t allow to change state
	if (this->player->is_moveing)this->change_state = false;

	this->update_buildings();

	if (this->quit)this->end_state();

}

void FirstVillage::update_input(const float& dt)
{
	this->update_mouse_position();
	this->try_to_end_state(sf::Keyboard::Escape);
	this->try_to_change_state();
}

void FirstVillage::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->setView(this->view);

	target->draw(this->map);
	player->render(target);
	if (draw_change_state_icon) {
		target->draw(this->change_state_icon);
	}
}

void FirstVillage::end_state()
{
	this->view.setSize(this->view_size);
	this->view.setCenter(this->view_size / 2.f);
	this->window->setView(this->view);
	this->save_data();
	this->manager->save_current_state(StateManager::FIRST_VILLAGE);
}

void FirstVillage::import_assets()
{
	this->map_texture = new sf::Texture;
	this->change_state_texture = new sf::Texture;
	this->map_texture->loadFromFile("Textures/Maps/2.png");
	this->change_state_texture->loadFromFile("Textures/Buttons/Enter.png");
	this->map.setTexture(*this->map_texture);
	this->change_state_icon.setTexture(*this->change_state_texture);
}

void FirstVillage::update_buildings()
{
	for (const BuildingBounds& building_bound: this->building_bounds) {
		if (Math::PointInsidePoligon(player->position, building_bound.polygon)) {
			printf("building\n");
		}

	}
}



void FirstVillage::save_data()
{
	//save player position;
	std::ofstream city_data;
	city_data.open("City/FirstVillage/data.txt");
	city_data << this->player->position.x << " ";
	city_data << this->player->position.y;
	city_data.close();
}

void FirstVillage::try_to_change_state()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		this->change_state = true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E) && this->change_state) {
		if (this->change_to_starting_city.contains(this->player->position)) {
			this->manager->switch_state(new StartingCity(this->window, this->manager));
			this->save_data();
		}
	}
}

void FirstVillage::import_data()
{
	//import player position
	std::ifstream city_data;
	sf::Vector2f player_position;
	city_data.open("City/FirstVillage/data.txt");
	city_data >> player_position.x;
	city_data >> player_position.y;
	city_data.close();
	//set Player Position
	this->player->set_position(player_position);
}



void FirstVillage::init_buildings()
{
	this->building_bounds.push_back({ Building::HOUSE_0,
		{
		{166,159},
		{195,173},
		{241,151},
		{241,136},
		{224,98},
		{180,120},
		}});
}
