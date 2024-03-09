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
	this->animation_manager->update(Animation::IDLE, { 140,100 }, dt);
}

void PlayerSide::init()
{
	this->animation_manager->add_animation(Animation::ROTATE, 8, 0);
	this->animation_manager->add_animation(Animation::WALKING, 8, 1);

}
