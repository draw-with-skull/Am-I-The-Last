#pragma once
#include <vector>
#include <string>
#include "State.h"
#include "StateManager.h"
#include "AssetImporter.h"
class Building:public State
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
	Building(INTERIOR type, sf::RenderWindow* window, StateManager* manager);
	virtual ~Building();

	// Inherited via State
	virtual void update(const float& dt) override;
	virtual void update_input(const float& dt) override;
	virtual void render(sf::RenderTarget* target) override;
	virtual void end_state() override;
	virtual void import_assets() override;

private:
	void import_data();
	void update_view();
	std::string get_type();
private:
	sf::Texture* interior_texture;
	sf::Sprite* interior;
	sf::View view;
	INTERIOR type;

	const sf::Vector2f view_size = sf::Vector2f(240, 135);

};

