#pragma once
#include "State.h"
#include "Button.h"
#include "Game.h"
class Resolution_meniu_state :
	public State
{
public://funtions
	void update_input(const float &dt);
	void update(const float &dt);
	void update_buttons();
	void render(sf::RenderTarget *target = nullptr);
	void import_assets() override;
	void render_buttons(sf::RenderTarget *target = nullptr);
	void end_state();
public://variables
private://functions
	void init_buttons();
	void import_textures();
	
private://variables
	sf::Sprite background;
	sf::Texture *background_texture;
	std::map<std::string, Button*>buttons;

public://constructors destructor
	Resolution_meniu_state(sf::RenderWindow *window, std::stack<State*>*states);
	virtual ~Resolution_meniu_state();
};

