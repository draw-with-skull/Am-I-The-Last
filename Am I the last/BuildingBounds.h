#pragma once
#include <SFML/System/Vector2.hpp>
#include "BuildingInterior.h"
struct BuildingBounds {
	BuildingInterior::INTERIOR type;
	std::vector<sf::Vector2f> polygon;
};