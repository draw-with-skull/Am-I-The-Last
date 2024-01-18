#include "Game.h"

void Game_state::render(sf::RenderTarget * target)
{
	if (!target)
		target = this->window;
	city.render_city(target);
}

void Game_state::update(const float &dt)
{ 
	this->update_mouse_position();
	this->update_input(dt);
	city.update_city(mouse_position_view,dt,this->window);
	
}

void Game_state::update_input(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{

		this->end_state();
	}
}

void Game_state::end_state()
{
	this->states->pop();
	printf("end game state");
}

void Game_state::init_keybinds()
{
	std::ifstream input_keybinds("Settings/Game_state_keybinds.txt");
	if (input_keybinds.is_open()) {

		std::string key_name = "";
		std::string key = "";
		while (input_keybinds >> key_name >> key) {
			this->keybinds[key_name] = this->supported_keys->at(key);
		}
	}
	input_keybinds.close();
}

void Game_state::init_data()
{
	window_size.x = this->window->getSize().x;
	window_size.y = this->window->getSize().y;
}

Game_state::Game_state(sf::RenderWindow *window, std::map<std::string,int> *supported_keys, std::stack<State*>*states)
	:State(window,supported_keys,states)
{
	init_keybinds();
	init_data();
	city.set_view(window);
}

Game_state::~Game_state()
{
}
