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
private:
	Player_top *player;
	sf::Texture* map_texture;
	sf::Sprite map;
	sf::View view;
	sf::FloatRect change_scene_to_first_village;
	const sf::Vector2f view_size = sf::Vector2f(480, 270);
};
