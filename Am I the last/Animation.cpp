#include "Animation.h"

Animation::Animation(sf::Texture* sprite_sheet, unsigned int frame_w, unsigned int frame_h, unsigned short frame_count, float frame_time, unsigned int frame_row)
{
	//init data about the frame
	this->frame_wigth = frame_w;
	this->frame_height = frame_h;
	this->frame_count = frame_count;
	this->frame_time = frame_time;
	this->frame_row = frame_row;
	//init sprite
	this->sprite.setTexture(*sprite_sheet);
	this->sprite.setOrigin(this->frame_wigth / static_cast<float>(2), this->frame_height / static_cast<float>(2));
	//init source rectangle
	this->source_rect.width = this->frame_height;
	this->source_rect.height = this->frame_wigth;
	this->source_rect.top = this->frame_row * this->frame_height;

}

void Animation::update(const sf::Vector2f position, const float& dt)
{
	if (!this->active) { return; }

	this->frame_time_left -= dt;

	if (this->frame_time_left < 0) {
		this->frame_time_left += this->frame_time;
		this->current_frame = ++this->current_frame % this->frame_count;
		this->source_rect.left = this->frame_wigth * this->current_frame;

		if (is_flipped) {
			this->source_rect.left += this->frame_wigth;
			this->source_rect.width = -(int)this->frame_wigth;
		}
		else {
			this->source_rect.width = this->frame_wigth;
		}
	}

	this->sprite.setTextureRect(this->source_rect);
	this->sprite.setPosition(position);
}

void Animation::render(sf::RenderTarget* window)
{
	window->draw(this->sprite);
}

void Animation::flip(const bool flip)
{
	this->is_flipped = flip;
}

void Animation::start()
{
	this->active = true;
}

void Animation::stop()
{
	this->active = false;
}

void Animation::reset()
{
	this->current_frame = 0;
	this->frame_time_left = frame_time;
}
