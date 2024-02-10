#include "State.h"


void State::update_mouse_position()
{
	this->mouse_position_screen = sf::Mouse::getPosition();
	this->mouse_position_window = sf::Mouse::getPosition(*this->window);
	this->mouse_position_view = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}

void State::check_for_quit()
{
}


void State::try_to_end_state(sf::Keyboard::Key key)
{
	if (sf::Keyboard::isKeyPressed(key)) {
		this->try_to_quit = true;
	}
	if (!sf::Keyboard::isKeyPressed(key)&&try_to_quit) {
		this->quit = true;
	}
}

State::State(sf::RenderWindow *window,StateManager*manager)
{
	this->window = window;
	this->manager = manager;
	this->quit = false;
	this->try_to_quit = false;
}

State::~State()
{
	printf("\ndelete state");
}
