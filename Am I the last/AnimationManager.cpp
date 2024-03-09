#include "AnimationManager.h"

AnimationManager::AnimationManager(sf::Texture* sprite_sheet, unsigned int frame_w, unsigned int frame_h, float frame_time)
{
	this->sprite_sheet = sprite_sheet;
	this->frame_w = frame_w;
	this->frame_h = frame_h;
	this->frame_time = frame_time;
}

AnimationManager::~AnimationManager()
{
	for (auto itr = animations.begin(); itr != animations.end(); itr++) {
		delete itr->second;
	}
	animations.clear();
}

void AnimationManager::add_animation(Animation::TYPE type, Animation* animation)
{
	this->existing_animations.push_back(type);
	this->animations.insert({type, animation});
}

void AnimationManager::add_animation(Animation::TYPE type, unsigned short frame_count, unsigned int frame_row)
{
	this->existing_animations.push_back(type);
	this->animations.insert({type,new Animation(this->sprite_sheet,this->frame_w,this->frame_w,frame_count,this->frame_time,frame_row)});
}

void AnimationManager::update(Animation::TYPE type, sf::Vector2f position, const float& dt)
{
	this->key = type;

	if (this->key == Animation::NONE) { return; }
	//the animation is not added
	if (!std::count(existing_animations.begin(), existing_animations.end(), this->key)) 
	{ 
		this->key = Animation::NONE;
		return; 
	}
	
	this->animations.at(this->key)->start();
	this->animations.at(this->key)->update(position, dt);
}

void AnimationManager::render(sf::RenderTarget* window)
{
	if (this->key == Animation::NONE) { return; }
	this->animations.at(this->key)->render(window);
}
