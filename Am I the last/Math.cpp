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

    int num_vertices = polygon.size();
    double x = point.x, y = point.y;
    bool inside = false;

    sf::Vector2f p1 = polygon[0], p2;

    for (int i = 1; i <= num_vertices; i++) {
        p2 = polygon[i % num_vertices];

        if (y > std::min(p1.y, p2.y)) {
            if (y <= std::max(p1.y, p2.y)) {
                if (x <= std::max(p1.x, p2.x)) {
                    double x_intersection
                        = (y - p1.y) * (p2.x - p1.x)
                        / (p2.y - p1.y)
                        + p1.x;

                    if (p1.x == p2.x
                        || x <= x_intersection) {
                        inside = !inside;
                    }
                }
            }
        }

        p1 = p2;
    }

    return inside;
}
