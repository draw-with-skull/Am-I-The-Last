#pragma once
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Window/Keyboard.hpp>
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
	void update_input();
	void update_animation_state();
private:
	float speed = 100;
	Animation::TYPE type;
	sf::Vector2f position{100,143};
	sf::Vector2f direction{ 0,0 };
	sf::Texture *sprite_sheet;
	AnimationManager *animation_manager;

};

