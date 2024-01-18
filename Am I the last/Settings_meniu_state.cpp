#include "Settings_meniu_state.h"

void Settings_meniu_state::update_input(const float & dt)
{
	this->check_for_quit();
}

void Settings_meniu_state::update(const float & dt)
{
	this->update_mouse_position();
	this->update_input(dt);
	this->update_buttons();

}

void Settings_meniu_state::update_buttons()
{
	for (auto&initializer : this->buttons)
	{
		initializer.second->update_button(this->mouse_position_view);
	}
	
	if (this->buttons["BUTTON_AUDIO"]->is_pressed()) {
		//add audio state
	}
	if (this->buttons["BUTTON_RESOLUTION"]->is_pressed()) {
		this->states->push(new Resolution_meniu_state(this->window, this->supported_keys, this->states));
	}
	if (this->buttons["BUTTON_DIFFICULTY"]->is_pressed()) {
		//resolution state
	}
	if (this->buttons["BUTTON_KEYBOARD"]->is_pressed()) {
		//resolution state
	}
	if (this->buttons["BUTTON_BACK"]->is_pressed()) {
		this->end_state();
	}
}

void Settings_meniu_state::render(sf::RenderTarget * target)
{
	if (!target)target = this->window;
	target->draw(this->background);
	this->render_buttons(target);
}

void Settings_meniu_state::render_buttons(sf::RenderTarget * target)
{
	for (auto&initializer : this->buttons)
		initializer.second->render_button(target);
}

void Settings_meniu_state::end_state()
{
	this->~Settings_meniu_state();
	this->states->pop();
}

void Settings_meniu_state::init_keybinds()
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

void Settings_meniu_state::init_buttons()
{
	this->buttons["BUTTON_AUDIO"] = new Button(240, 40, 96, 48, "Audio.png");
	this->buttons["BUTTON_RESOLUTION"] = new Button(240, 90, 128, 48, "Resolution.png");
	this->buttons["BUTTON_DIFFICULTY"] = new Button(240, 140, 128, 48, "DifFiculty.png");
	this->buttons["BUTTON_KEYBOARD"] = new Button(240, 190, 128, 48, "Keyboard.png");
	this->buttons["BUTTON_BACK"] = new Button(400, 220, 64, 48, "Back.png");
}

void Settings_meniu_state::import_textures()
{
	this->background_texture = new sf::Texture;
	this->background_texture->loadFromFile("Textures/Splash_Art/Wood_texture2.png");
	this->background.setTexture(*background_texture);
}

Settings_meniu_state::Settings_meniu_state(sf::RenderWindow *window, std::map<std::string, int>*supported_keys, std::stack<State*>*states)
	:State(window, supported_keys, states)
{
	printf("\n-----\nsettings_state");
	this->import_textures();
	this->init_keybinds();
	this->init_buttons();
}

Settings_meniu_state::~Settings_meniu_state()
{
	delete this->background_texture;
	//printf("\ndelete in settings background\n");
	for (auto initializer = this->buttons.begin(); initializer != this->buttons.end(); ++initializer) {
		delete initializer->second;
		//printf("\ndeleted button\n");
	}
	printf("\ndelete settings meniu");
}
