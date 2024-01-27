#include "Math.h"

sf::Vector2f Math::Normilize(sf::Vector2f vec)
{
	float lenght = sqrt(vec.x * vec.x + vec.y * vec.y);
	vec.x /= lenght;
	vec.y /= lenght;
	return vec;
}
