#include "Main_meniu_state.h"

void Main_meniu_state::update_input(const float & dt)
{
	this->check_for_quit();
}

void Main_meniu_state::update(const float & dt)
{
	this->update_mouse_position();
	this->update_input(dt);
	this->update_buttons();
}

void Main_meniu_state::update_buttons()
{
	for (auto&initializer : this->buttons) {
		initializer.second->update_button(this->mouse_position_view);
	}
	//buttons funtionality
	if (this->buttons["BUTTON_START"]->is_pressed())
	{
		this->states->push(new Game_state(this->window, this->supported_keys,this->states));
	}

	if (this->buttons["BUTTON_SETTINGS"]->is_pressed())
	{
		this->states->push(new Settings_meniu_state(this->window, this->supported_keys, this->states));
	}

	if (this->buttons["BUTTON_EXIT"]->is_pressed())
	{
		this->end_state();
	}

}

void Main_meniu_state::render(sf::RenderTarget * target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	this->render_buttons(target);
}

void Main_meniu_state::render_buttons(sf::RenderTarget *target)
{
	for (auto&initializer : this->buttons) {
		initializer.second->render_button(target);
	}
}

void Main_meniu_state::end_state()
{
	this->states->pop();
	this->~Main_meniu_state();
}


void Main_meniu_state::init_keybinds()
{
	std::ifstream input_keybinds("Settings/Main_meniu_state_keybinds.txt");
	if (input_keybinds.is_open()) {
		std::string key_name = "";
		std::string key = "";
		while (input_keybinds >> key_name >> key) {
			this->keybinds[key_name] = this->supported_keys->at(key);
		}
	}
	input_keybinds.close();
}


void Main_meniu_state::init_buttons()
{
	this->buttons["BUTTON_START"] = new Button(240, 100, 64, 48,"Start.png");
	this->buttons["BUTTON_SETTINGS"] = new Button(240, 150, 96, 48,"Settings.png");
	this->buttons["BUTTON_EXIT"] = new Button(240, 200, 64, 48,"Exit.png");
}

void Main_meniu_state::import_textures()
{
	this->background_texture = new sf::Texture;
	this->background_texture->loadFromFile("Textures/Splash_Art/start_meniu_Artwork.png");
	this->background.setTexture(*background_texture);
}

Main_meniu_state::Main_meniu_state(sf::RenderWindow * window, std::map<std::string, int>* supported_keys, std::stack<State*>*states)
	:State(window,supported_keys,states)
{	
	printf("\n-----\nmain_meniu_state");
	this->import_textures();
	this->init_keybinds();
	this->init_buttons();
}

Main_meniu_state::~Main_meniu_state()
{
	delete this->background_texture;
	for (auto initializer = this->buttons.begin(); initializer != this->buttons.end(); ++initializer) {
		delete initializer->second;
	}
	printf("\ndelete main meniu");
}
