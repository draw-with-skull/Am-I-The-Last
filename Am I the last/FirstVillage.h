#pragma once
#include "State.h"
#include "SFML/System.hpp"
class FirstVillage:public State
{
public:
	FirstVillage(sf::RenderWindow* window, StateManager* manager);
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;
};

