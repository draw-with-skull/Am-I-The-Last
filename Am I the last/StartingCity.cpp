#include "StartingCity.h"

StartingCity::StartingCity(sf::RenderWindow* window,StateManager* manager ):State(window,manager)
{
	printf("\n StartingCity");
	this->import_assets();
	this->view.setSize(this->view_size);
	this->player = new Player_top();
	this->import_data();
	this->change_scene_to_first_village = sf::FloatRect(0,190,50,70);
	this->init_buildings();
	this->draw_change_state_icon = false;
}

inline StartingCity::~StartingCity()
{

}

void StartingCity::update(const float& dt)
{
	update_input(dt);
	update_view(this->player->position);
	
	this->player->update(this->mouse_position_view,dt);

	if (this->player->is_moveing)this->change_state = false;

	this->update_buildings();
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
	if (draw_change_state_icon) {
		target->draw(this->change_state_icon);
	}
	//printf("\nrender");
}

void StartingCity::end_state()
{
	this->view.setSize(this->view_size);
	this->view.setCenter(this->view_size / 2.f);
	this->window->setView(this->view);
	this->save_data();
	this->manager->save_current_state(StateManager::STARTING_CITY);
}

void StartingCity::import_assets()
{
	this->map_texture = AssetImporter::get_texture(AssetImporter::CITY_MAP, "1");
	this->change_state_texture = AssetImporter::get_texture(AssetImporter::BUTTON, "Enter");

	this->map.setTexture(*this->map_texture);
	this->change_state_icon.setTexture(*this->change_state_texture);
}

void StartingCity::update_buildings()
{
	if (player->is_moveing) {
		return;
	}
	for (const BuildingBounds& building_bound : this->building_bounds) {
		if (Math::PointInsidePoligon(player->position, building_bound.polygon)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				this->manager->add_state(new BuildingInterior(building_bound.type, this->window, this->manager));
			}
		}
	}
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
			this->save_data();
		}
}

void StartingCity::init_buildings()
{
	this->building_bounds.push_back({ BuildingInterior::INTERIOR::HOUSE_0,
	{
	{166,159},
	{195,173},
	{241,151},
	{241,136},
	{224,98},
	{180,120},
	} });
	this->building_bounds.push_back({ BuildingInterior::INTERIOR::WATCH_TOWER,
	{
	{261,224},
	{323,253},
	{384,223},
	{353,126},
	{322,95},
	{291,124}
	} });
}
