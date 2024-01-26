#include "City.h"

void City::render_city(sf::RenderTarget * target)
{
	target->draw(this->city_sprite);
	player.render_player(target);
}

void City::update_city(sf::Vector2f mouse_position,const float &dt,sf::RenderTarget *target)
{
	//update player
	player.update_player(mouse_position, dt);
	update_view(target);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		set_view(target);

	//colision check
	if (!player.is_moveing&&!checked) 
	{
		for (unsigned int i = 0; i < buildings_count; i++)
			if (building[i].is_close(player.player_position))
				if (building[i].collision(player.player_position))
				{
					//need to add some stuff, later
					checked = true;
				}
		checked = true;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))checked = false;
}


void City::import_city_data()
{
	//bloody magic if it works
	//import city texture
	this->city_texture = new sf::Texture;
	this->city_texture->loadFromFile("Textures/Maps/1.png");
	this->city_sprite.setTexture(*city_texture);

	//import city information(bulding colision shape)
	std::ifstream city_data;
	city_data.open("City/city_1/data.txt");
	city_data >> buildings_count;

	//reading from file
	for (unsigned int i = 0; i < buildings_count; i++)
		building.push_back(Building(city_data));
	city_data.close();
}

void City::update_view(sf::RenderTarget *target)
{
	//needs some tidy up
	position.x = player.player_sprite.getPosition().x-224 ;
	position.y = player.player_sprite.getPosition().y-119 ;
	if (position.x < 0)position.x = 0; 
	if (position.y < 0)position.y = 0;
	if (position.x > city_sprite.getTexture()->getSize().x - 480) position.x = city_sprite.getTexture()->getSize().x- 480;
	if (position.y > city_sprite.getTexture()->getSize().y - 270) position.y = city_sprite.getTexture()->getSize().y- 270;
	city_view.reset(sf::FloatRect(position.x, position.y, 480, 270));
	target->setView(city_view);
}

void City::set_view(sf::RenderTarget *target)
{
	city_view.reset(sf::FloatRect(0, 0, 480, 270));
	city_view.setViewport(sf::FloatRect(0, 0, 1, 1));
	target->setView(city_view);
}


City::City()
{
	printf("\n-----\ncity");
	this->import_city_data();
}

City::~City()
{
	delete this->city_texture;
}
