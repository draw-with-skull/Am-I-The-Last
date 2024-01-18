#include "Entity.h"



void Entity::create_sprite(sf::Texture *texture)
{
	this->entity_texture = texture;
	this->entity_sprite->setTexture(*this->entity_texture);
}

void Entity::set_position(const float x, const float y)
{
	if (this->entity_sprite)
		this->entity_sprite->setPosition(x,y);
}

void Entity::update(const float & dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	if(this->entity_sprite)
		target->draw(*this->entity_sprite);
}

void Entity::move(const float &dt,const float dir_x, const float dir_y)
{
	
}

void Entity::init_variables()
{
	this->entity_texture = nullptr;
	this->entity_sprite = nullptr;
	this->movement_speed = 100.f;
}

Entity::Entity()
{
	this->init_variables();
	
}
Entity::~Entity()
{
	delete this->entity_sprite;
}
