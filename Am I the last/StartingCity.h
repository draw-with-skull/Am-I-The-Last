#pragma once
#include"State.h"
#include"Player_top.h"
#include"StateManager.h"
class StartingCity:public State
{
public:
	StartingCity(sf::RenderWindow* window,StateManager* manager);
	virtual ~StartingCity();
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;
private:
	void update_view();
	void import_data();
	void save_data();
	void try_to_change_state();
private:
	bool change_state = false,draw_change_state_icon;
	Player_top *player;
	sf::Texture* map_texture,*change_state_texture;
	sf::Sprite map,change_state_icon;
	sf::View view;
	sf::FloatRect change_scene_to_first_village;
	const sf::Vector2f view_size = sf::Vector2f(480, 270);
};
