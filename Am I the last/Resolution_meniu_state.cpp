#include "Resolution_meniu_state.h"

void Resolution_meniu_state::update_input(const float & dt)
{
	this->check_for_quit();
}

void Resolution_meniu_state::update(const float & dt)
{
	this->update_mouse_position();
	this->update_input(dt);
	this->update_buttons();
}

void Resolution_meniu_state::update_buttons()
{
	for (auto&initializer : this->buttons)
	{
		initializer.second->update_button(this->mouse_position_view);
	}
	
	//if (buttons["BUTTON_SIZE1"]->is_pressed())window->setSize(sf::Vector2u(1920,800));
	if (buttons["BUTTON_SIZE2"]->is_pressed())window->setSize(sf::Vector2u(1600, 900));
	if (buttons["BUTTON_SIZE3"]->is_pressed())window->setSize(sf::Vector2u(1536, 864));
	if (buttons["BUTTON_SIZE4"]->is_pressed())window->setSize(sf::Vector2u(1440, 900));
	if (buttons["BUTTON_SIZE5"]->is_pressed())window->setSize(sf::Vector2u(1336, 768));
	if (buttons["BUTTON_SIZE6"]->is_pressed())window->setSize(sf::Vector2u(1280, 720));
	if (buttons["BUTTON_BACK"]->is_pressed())this->end_state();
}

void Resolution_meniu_state::render(sf::RenderTarget * target)
{
	if (!target)target = this->window;
	target->draw(this->background);
	this->render_buttons(target);
}

void Resolution_meniu_state::import_assets()
{
}

void Resolution_meniu_state::render_buttons(sf::RenderTarget * target)
{
	for (auto&initializer : this->buttons)
		initializer.second->render_button(target);
}

void Resolution_meniu_state::end_state()
{
	this->~Resolution_meniu_state();
	this->manager->revome_state();
}


void Resolution_meniu_state::init_buttons()
{
	//this->buttons["BUTTON_SIZE1"] = new Button(240, 40, 128, 48, "Size1.png");
	this->buttons["BUTTON_SIZE2"] = new Button(240, 20, 128, 48, "Size2.png");
	this->buttons["BUTTON_SIZE3"] = new Button(240, 70, 128, 48, "Size3.png");
	this->buttons["BUTTON_SIZE4"] = new Button(240, 120, 128, 48, "Size4.png");
	this->buttons["BUTTON_SIZE5"] = new Button(240, 170, 128, 48, "Size5.png");
	this->buttons["BUTTON_SIZE6"] = new Button(240, 220, 128, 48, "Size6.png");
	this->buttons["BUTTON_BACK"] = new Button(400, 220, 64, 48, "Back.png");
}

void Resolution_meniu_state::import_textures()
{

	this->background_texture = new sf::Texture;
	this->background_texture->loadFromFile("Textures/Splash_Art/Wood_texture1.png");
	this->background.setTexture(*background_texture);
}


Resolution_meniu_state::Resolution_meniu_state(sf::RenderWindow * window,StateManager* states)
	:State(window,states)
{
	this->import_textures();
	this->init_buttons();
}

