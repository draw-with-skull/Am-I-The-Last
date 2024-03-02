#pragma once
#include"Player_top.h"
#include "BuildingBounds.h"
class City
{
public:
	virtual ~City();

	virtual void update_view(const sf::Vector2f position);

	virtual void update_buildings() =0;
	virtual void try_to_change_state()=0;
	virtual void init_buildings()=0;
	virtual void import_data()=0;
	virtual void save_data()=0;
protected:
	bool change_state = false, draw_change_state_icon;
	
	const sf::Vector2f view_size = sf::Vector2f(480, 270);
	sf::Texture* map_texture, * change_state_texture;
	sf::Sprite map, change_state_icon;
	sf::View view;
	
	std::vector<BuildingBounds> building_bounds;

	Player_top* player;
};

