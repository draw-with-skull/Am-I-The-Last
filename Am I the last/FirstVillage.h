#pragma once
#include "Player_top.h"
#include "State.h"
#include "SFML/System.hpp"
#include "StartingCity.h"
class FirstVillage:public State
{
public:
	FirstVillage(sf::RenderWindow* window, StateManager* manager);
	virtual ~FirstVillage();
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;

private:

	void update_view();
	void importa_data();
	void save_data();
	void try_to_change_state();

private:
	bool change_state = false, draw_change_state_icon;
	Player_top* player;
	sf::Texture* map_texture, * change_state_texture;
	sf::Sprite map, change_state_icon;
	sf::View view;
	sf::FloatRect change_to_starting_city;
	const sf::Vector2f view_size = sf::Vector2f(480, 270);
};

