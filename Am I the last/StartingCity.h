#pragma once
#include"State.h"
class StartingCity:State
{
public:
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
public:
	//StartingCity(sf::RenderWindow *window):State(window,){;
};

