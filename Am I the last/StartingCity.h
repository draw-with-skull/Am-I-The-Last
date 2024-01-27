#pragma once
#include"State.h"
class StartingCity:public State
{
public:
	StartingCity(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~StartingCity();
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;
private:
	void update_view();
private:
	sf::Texture* map_texture;
	sf::Sprite map;
	sf::View view;
	const sf::Vector2f view_size = sf::Vector2f(480, 270);

};
