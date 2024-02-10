#include "FirstVillage.h"

FirstVillage::FirstVillage(sf::RenderWindow* window, StateManager* manager)
	:State(window,manager)
{
	printf("\n FirstVillage");
	this->import_assets();
	this->view.setSize(this->view_size);
	this->player = new Player_top();
	this->importa_data();
	this->change_to_starting_city = sf::FloatRect(460,220,50,70);
}

FirstVillage::~FirstVillage()
{
	delete this->player;
	delete this->map_texture;
}

void FirstVillage::update(const float& dt)
{
	this->update_input(dt);
	this->update_view();
	this->player->update(this->mouse_position_view, dt);
	//if player is moveing don t allow to change state
	if (this->player->is_moveing)this->change_state = false;

	if (this->quit)this->end_state();

	//determines if it should show the change state icon
	if (!this->player->is_moveing) {
		if (this->change_to_starting_city.contains(this->player->position)) {
			this->change_state_icon.setPosition(this->change_to_starting_city.getPosition());
			this->draw_change_state_icon = true;
		}
		else {
			this->draw_change_state_icon = false;
		}
	}
	else {
		this->draw_change_state_icon = false;
	}

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
}

void FirstVillage::import_assets()
{
	this->map_texture = new sf::Texture;
	this->change_state_texture = new sf::Texture;
	this->map_texture->loadFromFile("Textures/Maps/2.png");
	this->change_state_texture->loadFromFile("Textures/Buttons/Enter.png");
	this->map.setTexture(*this->map_texture);
	this->change_state_icon.setTexture(*this->change_state_texture);

	this->change_state_icon.setOrigin(this->change_state_icon.getPosition().x / 2, this->change_state_icon.getPosition().y / 2);

}

void FirstVillage::update_view()
{
	sf::Vector2f view_center = this->player->position;
	sf::Vector2f map_size = sf::Vector2f(map_texture->getSize());

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

void FirstVillage::importa_data()
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
