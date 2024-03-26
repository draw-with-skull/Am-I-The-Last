#pragma once
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetImporter.h"
#include <SFML/Graphics/Sprite.hpp>
class Building
{
public:
	Building(const std::string textur_name,sf::RenderWindow *target);
	virtual ~Building();

	virtual void update(const float& dt, sf::Vector2f position) = 0;
	virtual void render(const sf::RenderTarget* target)=0;
protected:
	void update_view(const sf::Vector2f position);
protected:
	sf::Texture* interior_texture;
	sf::Sprite* interior;
	sf::RenderWindow* window;
	sf::View view;
	const sf::Vector2f view_size = sf::Vector2f(240, 135);
};

