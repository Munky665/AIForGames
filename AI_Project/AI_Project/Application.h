#pragma once
#include <SFML/Graphics.hpp>

namespace App {

	class Application
	{
	private:
		sf::RenderWindow* window;
		sf::CircleShape shape{ 100.f };
		bool m_gameOver;
	public:
		Application();
		void Run(std::string string, float width, float height);
		virtual bool StartUp() = 0;
		virtual void ShutDown() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Draw() = 0;
		void Quit() { m_gameOver = true; }
		~Application();
	};
}
