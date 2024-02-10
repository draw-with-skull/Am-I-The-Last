#pragma once
#include<SFML/System/Vector2.hpp>
#include<math.h>
#include<vector>
class Math
{
public:
	static sf::Vector2f Normilize(sf::Vector2f vec);
	static bool PointInsidePoligon(sf::Vector2f point, std::vector<sf::Vector2f> polygon);
};

