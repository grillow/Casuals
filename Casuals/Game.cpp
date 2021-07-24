#include "Game.h"
#include "RenderUtils.h"
#include "Light.h"
#include <thread>
#include <chrono>
#include <algorithm>

void Game::Run()
{
	RenderUtils::Init();
	MainLoop();
}

void Game::MainLoop()
{
	mapManager.Load(1);
	sf::Clock deltaClock;
	while (/*RenderUtils::window->isOpen()*/ true)
	{
		float deltaTime = deltaClock.restart().asSeconds();
		ProcessEvents();
		RenderUtils::window->clear(sf::Color::Black);
		Update(deltaTime);
		RenderUtils::window->display();
		RenderUtils::FPS = std::min((int)(1000 / deltaTime), RenderUtils::MAX_FPS);
		std::this_thread::sleep_for(std::chrono::milliseconds( (int)std::max( (RenderUtils::MS_PER_FRAME - 1000 * deltaTime), 0.0f ) ));
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (RenderUtils::window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			RenderUtils::window->close();
			exit(0);
		}
	}
}

void Game::Logic(float deltaTime)
{
	Player.GetInput(&Input);
	EntityManager::Update(deltaTime);
}

void Game::Render()
{
	//RenderUtils::DrawGrid(1, sf::Color(255, 255, 255, 31));
	Light::LightUp(&Player);
	EntityManager::Draw();
}

void Game::Update(float deltaTime)
{
	Input.Update();									//  Input
	Logic(deltaTime);								//  Update logic
	Render();										//  Draw
}
