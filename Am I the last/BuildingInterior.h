#pragma once
#include <vector>
#include <string>
#include "State.h"
#include "AssetImporter.h"
#include "PlayerSide.h"
#include "BuildingSingleInterior.h"

class BuildingInterior :public State
{
public:
	enum INTERIOR
	{
		HOUSE_0,
		HOUSE_1,
		HOUSE_2,
		HOUSE_3,
		HOUSE_4,
		HOUSE_5,
		HOUSE_6,
		HOUSE_7,
		HOUSE_8,
		HOUSE_9,
		WATCH_TOWER,

	};
public://constructor destructor
	BuildingInterior(INTERIOR type, sf::RenderWindow* window, StateManager* manager);
	virtual ~BuildingInterior();

	sf::Vector2f get_position();
	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;
private:
	Building *building;
	INTERIOR type;
	PlayerSide player;
};

