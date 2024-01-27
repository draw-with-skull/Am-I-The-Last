#pragma once
#include "Button.h"
#include "StartingCity.h"
#include "Settings_meniu_state.h"
#include "StateManager.h"
class Main_meniu_state :
	public State
{
public://functions
	void update_input(const float &dt);
	void update(const float &dt);
	void update_buttons();
	void render(sf::RenderTarget *target = nullptr);
	void render_buttons(sf::RenderTarget *target=nullptr);
	virtual void import_assets() override;
	void end_state();
public://variables

private://functions
	void init_buttons();
	void import_textures();
private://variables
	sf::Sprite background;
	sf::Font game_font;
	sf::Texture *background_texture;
	std::map<std::string, Button*>buttons;

	
	
public://constructor destructor
	Main_meniu_state(sf::RenderWindow *window, StateManager* manager);
	virtual ~Main_meniu_state();

	// Inherited via State
	
};

