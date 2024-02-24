#include "Game.h"


void Game::update_dt()
{
	//used for a more stable frame rate
	this->dt = this->dt_Clock.restart().asSeconds();
	//printf("%f\n", dt);
}

void Game::update_events_sfml()
{	
	//checks for events 
	while (this->window->pollEvent(this->sf_event)) {
		switch (sf_event.type) {
		case sf::Event::Closed: {
			//add all saveing stuff
			this->save_window_settings();
			this->window->close();
		}break;
		case sf::Event::Resized: {
			this->save_window_settings();
		}
		break;
		}
	}
}

void Game::update()
{
	//update events
	this->update_events_sfml();

	if (this->state_manager->get_state()) {
		//returns nullptr if the state stack ins empty
		this->state_manager->get_state()->update(this->dt);
	}
	else
	{
		//Aplication end
		this->window->close();
		this->end_application();
	}
}

void Game::render()
{
	//clears window
	this->window->clear();

	//rendering
	if (this->state_manager->get_state()) {
		this->state_manager->get_state()->render();
	}
	//display
	this->window->display();
}

void Game::run()
{	
	//main game loop
	while (this->window->isOpen()) {
		this->update_dt();
		this->update();
		this->render();
	}
}
void Game::end_application()
{
	//Saveing stuff (need to do)
	printf("\nEnding aplications");
}

void Game::create_window()
{	
	//imports the settings for the window and creates one
	this->init_window();
	this->window = new sf::RenderWindow(sf::VideoMode(480,270), "Am I the last");
	//Scales window and centres it
	this->window->setSize(window_scale);
	this->window->setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width - window_scale.x)/2, (sf::VideoMode::getDesktopMode().height - window_scale.y)/2 ));
	this->window->setFramerateLimit(60);
}

void Game::init_State()
{

	this->state_manager->add_state(new Main_meniu_state(this->window, this->state_manager));
} 

void Game::init_window()
{	
	//importing settings for the window
	std::ifstream window_settings;
	window_settings.open("Settings/Window_settings.txt");
	window_settings >> window_scale.x;
	window_settings >> window_scale.y;
	window_settings.close();
}

void Game::save_window_settings()
{
	std::ofstream window_settings;
	window_settings.open("Settings/Window_settings.txt", std::ofstream::out |std::ofstream::trunc );
	window_settings << window->getSize().x << std::endl;
	window_settings << window->getSize().y;
	window_settings.close();
}


Game::Game() {
	printf("\n-----\ngame");
	this->create_window();
	this->state_manager = new StateManager();
	this->init_State();
	
}
Game::~Game()
{	
	delete this->state_manager;
	delete this->window;
	
	printf("\ndelete game");
}
