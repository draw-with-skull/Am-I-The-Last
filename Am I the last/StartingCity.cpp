#include "StartingCity.h"

StartingCity::StartingCity(sf::RenderWindow* window, std::stack<State*>* states):State(window,states)
{
	printf("\n StartingCity");
}

void StartingCity::update(const float& dt)
{
}

void StartingCity::update_input(const float& dt)
{
}

void StartingCity::render(sf::RenderTarget* target)
{
}

void StartingCity::end_state()
{
}
