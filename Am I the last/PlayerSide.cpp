#include "PlayerSide.h"

PlayerSide::PlayerSide()
{
	this->sprite_sheet = AssetImporter::get_texture(AssetImporter::ENTITY, "player");
	this->animation_manager = new AnimationManager(sprite_sheet,32,32,0.1);
	this->init();
}

PlayerSide::~PlayerSide()
{
}

void PlayerSide::render(sf::RenderTarget* window)
{
	this->animation_manager->render(window);
}

void PlayerSide::update(sf::Vector2f mouse_position, const float& dt)
{
	this->update_input();
	this->update_animation_state();
	this->position += this->direction * speed * dt;
	
	this->animation_manager->update(type, this->position, dt);
}

void PlayerSide::init()
{
	this->animation_manager->add_animation(Animation::ROTATE, 8, 0);
	this->animation_manager->add_animation(Animation::WALKING, 8, 1);

}

void PlayerSide::update_input()
{
	this->direction={ 0,0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		this->direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->direction.x = 1;
	}
}

void PlayerSide::update_animation_state()
{
	if (direction.x == 0 && direction.y == 0) {
		this->type = Animation::ROTATE;
	}

	if (direction.x != 0 && direction.y == 0) {
		this->type = Animation::WALKING;
	}
}
