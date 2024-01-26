#include "State.h"

void State::update(const float &dt)
{
}

void State::update_input(const float & dt)
{
}

void State::update_mouse_position()
{
	this->mouse_position_screen = sf::Mouse::getPosition();
	this->mouse_position_window = sf::Mouse::getPosition(*this->window);
	this->mouse_position_view = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}

void State::render(sf::RenderTarget *target)
{
}

void State::end_state()
{

}

void State::check_for_quit()
{
	
}


State::State(sf::RenderWindow *window, std::stack<State*>*states)
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::~State()
{
	printf("\ndelete state");
}
