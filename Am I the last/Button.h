#pragma once
#include<SFML/Graphics.hpp>
#include<string>

enum button_states { button_idle = 0, button_hover = 1, button_pressed = 2 };
class Button
{
public://funtions
	void render_button(sf::RenderTarget* target);
	void update_button(const sf::Vector2f mouse_position);
	const bool is_pressed() const;
public://variables
	short unsigned button_state=button_idle;
	bool is_released = false;
private://funtions
	void Import_button_texture(std::string file_name);
private://variables
	//texture based button
	sf::RectangleShape button_shape;
	sf::Texture *button_texture;
	sf::Sprite button_sprite;
	//plain button
	//others
	unsigned short width;
	unsigned short height;

public://constructor destructor
	Button(unsigned short x, unsigned short y,unsigned short width, unsigned short height, std::string filename);
	virtual ~Button();
};

