#pragma once
#include "State.h"
#include "StartingCity.h"
#include "BuildingInterior.h"
#include "City.h"
class FirstVillage:public State,public City
{
public:
	FirstVillage(sf::RenderWindow* window, StateManager* manager);
	virtual ~FirstVillage();
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;

private:
	// Inherited via City
	virtual void update_buildings() override;
	virtual void init_buildings() override;
	virtual void try_to_change_state() override;
	virtual void import_data()override;
	virtual void save_data()override;
private:
	sf::FloatRect change_to_starting_city;
};

