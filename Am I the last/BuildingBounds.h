#pragma once
#include <SFML/System/Vector2.hpp>
#include "Building.h"
struct BuildingBounds {
	Building::INTERIOR type;
	std::vector<sf::Vector2f> polygon;
};