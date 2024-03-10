#pragma once
#include"Animation.h"
#include <map>

class AnimationManager
{
public:
	AnimationManager(sf::Texture* sprite_sheet, unsigned int frame_w, unsigned int frame_h, float frame_time);
	virtual ~AnimationManager();
public:
	void add_animation(Animation::TYPE type, Animation* animation);
	void add_animation(Animation::TYPE type, unsigned short frame_count,unsigned int frame_row);
	void update(Animation::TYPE type, sf::Vector2f position, const float& dt);
	void render(sf::RenderTarget* window);
	void flip(bool flip);
private:
	sf::Texture* sprite_sheet;
	bool fliped{ false };
	unsigned int frame_w{ 0 };
	unsigned int frame_h{ 0 };
	float frame_time{ 0 };
	Animation::TYPE key{ Animation::TYPE::NONE };
	std::map < Animation::TYPE, Animation*> animations;
	std::vector<Animation::TYPE> existing_animations;
};

