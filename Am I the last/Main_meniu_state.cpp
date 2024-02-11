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
		this->init_state();
	}

	if (this->buttons["BUTTON_SETTINGS"]->is_pressed())
	{
		this->manager->add_state(new Settings_meniu_state(this->window, this->manager));
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

void Main_meniu_state::import_assets()
{
}

void Main_meniu_state::end_state()
{
	this->~Main_meniu_state();
	this->manager->revome_state();
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

void Main_meniu_state::init_state()
{
	std::ifstream stream;
	StateManager::STATE_NAME state_name;
	int value;
	//reads value from file and cast it do the enum 
	stream.open("Settings/LastState.txt");
	stream >> value;
	state_name = static_cast<StateManager::STATE_NAME>(value);


	State* state{};
	switch (state_name) {
		case StateManager::STARTING_CITY: {
			state = new StartingCity(this->window, this->manager);
		}break;
		case StateManager::FIRST_VILLAGE: {
			state = new FirstVillage(this->window, this->manager);
		}break;
			//case StateManager:: :{}break;
		default: {
			state = new StartingCity(this->window, this->manager);
		}break;
	}

	//new Main_meniu_state(this->window, this->state_manager)
	this->manager->add_state(state);
}

Main_meniu_state::Main_meniu_state(sf::RenderWindow* window, StateManager* manager)
	:State(window, manager)
{	
	printf("\n-----\nmain_meniu_state");
	this->import_textures();
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
