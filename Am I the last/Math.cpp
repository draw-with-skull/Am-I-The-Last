#include "Math.h"

sf::Vector2f Math::Normilize(sf::Vector2f vec)
{
	float lenght = sqrt(vec.x * vec.x + vec.y * vec.y);
	vec.x /= lenght;
	vec.y /= lenght;
	return vec;
}

bool Math::PointInsidePoligon(sf::Vector2f point, std::vector<sf::Vector2f> polygon)
{
	if (polygon.size() < 3) {
		printf("not a poly");
		return false;
	}

	bool inside = false;
	sf::Vector2f p1 = polygon[0],p2;
	unsigned int vertex_count= polygon.size();

	for (int i = 1; i < vertex_count; i++) {
		p2 = polygon[i%vertex_count];

		if (point.y > std::min(p1.y, p2.y)) {
			if (point.y <= std::max(p1.y, p2.y)) {
				if (point.x <= std::max(p1.x,p2.x)) {
					float intersection = (point.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;

					if (p1.x == p2.x || point.x <= intersection) {
						inside = !inside;
					}
				}
			}
		}
		p1 = p2;
	}
	return inside;
}
