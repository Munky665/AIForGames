#include "Application.h"


namespace App {
	Application::Application()
	{
	}

	void Application::Run(std::string string, float width, float height)
	{
		window = new sf::RenderWindow(sf::VideoMode(width, height), string);
		sf::Clock clock;
		double prevTime = clock.getElapsedTime().asSeconds();
		double currTime = 0;
		double deltaTime = 0;

		if (!StartUp())
		{
			window->close();
		}
		else
		{
			currTime = clock.getElapsedTime().asSeconds();
			deltaTime = currTime - prevTime;
			prevTime = currTime;

			shape.setFillColor(sf::Color::Green);

			while (!m_gameOver)
			{
				sf::Event event;
				while (window->pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window->close();
				}
				Update(deltaTime);
				Draw();
			}
		}
	}

	void Application::Draw()
	{
		window->clear();
		window->draw(shape);
		window->display();
	}

	Application::~Application()
	{
	}
}