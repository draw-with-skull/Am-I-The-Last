#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
class Animation
{
public:
	Animation(sf::Texture *sprite_sheet,unsigned int frame_w,unsigned int frame_h,unsigned short frame_count,float frame_time,unsigned int frame_row);
	//virtual ~Animation();
public:
	void update(const sf::Vector2f position, const float& dt);
	void render( sf::RenderTarget* window);
	void flip(const bool flip);
	void start();
	void stop();
	void reset();
private:
	unsigned short frame_count{ 0 };
	unsigned short current_frame{ 0 };
	
	unsigned int frame_height{ 0 };
	unsigned int frame_wigth{ 0 };
	unsigned int frame_row{ 0 };
	
	float frame_time{ 0 };
	float frame_time_left{ 0 };
	
	bool active{ false };
	bool continuous{ false };

	sf::Sprite sprite;
	sf::IntRect source_rect;



};

