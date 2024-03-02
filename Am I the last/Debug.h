#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Debug
{
public:
	static void DrawPoligon(std::vector<sf::Vector2f> polygon, sf::RenderTarget *window);
};

