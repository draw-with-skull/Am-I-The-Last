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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{

		this->end_state();
	}
}

void Game_state::end_state()
{
	this->states->pop();
	printf("end game state");
}



void Game_state::init_data()
{
	window_size.x = this->window->getSize().x;
	window_size.y = this->window->getSize().y;
}

Game_state::Game_state(sf::RenderWindow *window, std::stack<State*>*states)
	:State(window,states)
{
	init_data();
	city.set_view(window);
}

Game_state::~Game_state()
{
}
