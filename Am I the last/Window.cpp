#include"Window.h"

void Window::create_window()
{
	init_Window();
	this->window = new sf::RenderWindow(sf::VideoMode(window_size.x, window_size.y), "Am I the last");
}

void Window::init_Window()
{
		std::ifstream window_settings;
		window_settings.open("Settings.txt");
		window_settings >> window_size.x;
		window_settings >> window_size.y;
		window_settings.close();
		
}

Window::Window() 
{
}
Window::~Window()
{
	delete this->window;
}
