#include "Building.h"
#define Offset 16
//const bool Building::collision_AABB(sf::Vector2f player_position)
//{
//	unsigned short true_value = 0;
//	if (A.x < player_position.x &&player_position.x < B.x)
//		true_value += 1;
//	if (A.y < player_position.y&&player_position.y < D.y)
//		true_value += 1;
//	if (A.x < player_position.x  && player_position.x  < B.x)
//		true_value += 1;
//	if (A.y < player_position.y  && player_position.y  < D.y)
//		true_value += 1;
//
//	if (true_value >= 2)
//		return true;
//	else
//		return false;
//}

const bool Building::collision(sf::Vector2f player_position)
{
	/*player_position.x += Offset;
	player_position. += Offset;*/
	float local_distance = 0;
	local_distance += distance(A, player_position);
	local_distance += distance(B, player_position);
	local_distance += distance(C, player_position);
	local_distance += distance(D, player_position);
	if (local_distance < building_size)
		return true;
	else 
		return false;
}

const bool Building::is_close(sf::Vector2f player_position)
{
	if (distance(player_position, centre) <= building_radius)
		return true;
	else
		return false;
}

void Building::init_building_data(std::ifstream& building_data)
{
	building_data >> A.x >> A.y;
	building_data >> B.x >> B.y;
	building_data >> C.x >> C.y;
	building_data >> D.x >> D.y;
	this->get_centre();
	this->get_size();
	this->building_radius=this->get_radius();
	//printf("\n Radius %f", building_radius);
}

float Building::distance(sf::Vector2f point_1, sf::Vector2f point_2) 
{
	return sqrt(pow((point_2.x-point_1.x),2) + pow((point_2.y - point_1.y), 2));
}

void Building::get_centre()
{
	this->centre.x = (A.x + C.x) / 2.f;
	this->centre.y = (A.y + C.y) / 2.f;
}

void Building::get_size()
{
	this->building_size += this->distance(A, B);
	this->building_size += this->distance(A, D);
	this->building_size += this->distance(A,centre);
	this->building_size += this->distance(B,centre);
	//printf("\n%f", this->distance(A, centre));
	//printf("\n%f", this->distance(B, centre));
}

float Building::get_radius()
{
	if (distance(A, centre) > distance(B, centre))
		return distance(A, centre);
	else
		return distance(B, centre);
}

Building::Building(std::ifstream& building_data)
{
	this->init_building_data(building_data);
	
}

Building::~Building()
{
}
