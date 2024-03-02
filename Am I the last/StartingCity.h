#pragma once

#include"State.h"
#include"StateManager.h"
#include"AssetImporter.h"
#include "City.h"
#include "FirstVillage.h"

#include "Debug.h"

class StartingCity:public State,public City
{
public:
	StartingCity(sf::RenderWindow* window,StateManager* manager);
	virtual ~StartingCity();
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
	sf::FloatRect change_scene_to_first_village;
};
