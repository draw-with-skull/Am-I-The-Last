#pragma once
#include <SFML/System/Vector2.hpp>
#include <fstream>
class Building
{	
public://funtions
	const bool collision(sf::Vector2f player_position);
	const bool is_close(sf::Vector2f player_position);
public://variables

private://funtions
	void init_building_data(std::ifstream& building_data);
	void get_centre();
	void get_size();
	float get_radius();

	float distance(sf::Vector2f point_1, sf::Vector2f point_2);
private://varialbes
	sf::Vector2f A,B,C,D,centre;

	unsigned short building_id;
	float building_size=0,building_radius;
	bool looted = false;

public://constructor destructor
	Building(std::ifstream &building_data);
	virtual ~Building();
};

