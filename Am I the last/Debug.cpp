#include "Debug.h"

void Debug::DrawPoligon(std::vector<sf::Vector2f> polygon, sf::RenderTarget* window)
{
	if (polygon.size() < 3) {
		printf("not a polygon\n");
		return;
	}
	sf::VertexArray shape(sf::Lines, (polygon.size())*3);
	int vertexcount = 0;
	for (int i = 0; i < polygon.size()-0; i++) {
		shape[vertexcount] = polygon[i% polygon.size()];
		shape[vertexcount++].color = sf::Color::Red;
		shape[vertexcount] = polygon[(i+1)%polygon.size()];
		shape[vertexcount++].color = sf::Color::Red;
	}

	window->draw(shape);


}
/*
3 3
4 6
5 9
*/
