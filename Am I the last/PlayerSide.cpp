#include "PlayerSide.h"

PlayerSide::PlayerSide()
{
	this->sprite_sheet = AssetImporter::get_texture(AssetImporter::ENTITY, "player");
	this->animation = new Animation(sprite_sheet,32,32,8,0.1f,0);
	this->animation->start();
}

PlayerSide::~PlayerSide()
{
}

void PlayerSide::render(sf::RenderTarget* window)
{
	animation->render(window);
}

void PlayerSide::update(sf::Vector2f mouse_position, const float& dt)
{
	animation->update({ 100,100 }, dt);
}

void PlayerSide::init()
{
}
