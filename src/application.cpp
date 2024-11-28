#include "application.hpp"

Application::Application() {}

Application::~Application() {}

void Application::start()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "ChessLike Game");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		on_update();

		window.clear();
		window.display();
	}
}

void Application::on_update()
{
}
