#pragma once
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Sprite.hpp>
#include"AnimationManager.h"
#include"AssetImporter.h"
class PlayerSide
{
public:
	PlayerSide();
	virtual ~PlayerSide();
public:
	void render(sf::RenderTarget* window);
	void update(sf::Vector2f mouse_position, const float& dt);
private:
	void init();

private:
	sf::Texture *sprite_sheet;
	AnimationManager *animation_manager;

};

