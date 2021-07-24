#include "GameInput.h"
#include "RenderUtils.h"
#include <SFML/Window/Keyboard.hpp>

void GameInput::Update()
{
	if (!RenderUtils::window->hasFocus())
	{
		Left = Right = Up = Down = Shoot = false;
		return;
	}

	bool LeftArrow = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool RightArrow = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	bool UpArrow = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	bool DownArrow = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	bool A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	bool left = LeftArrow || A;
	bool right = RightArrow || D;
	bool up = UpArrow || W;
	bool down = DownArrow || S;

	Left = left && !right;
	Right = right && !left;
	Up = up && !down;
	Down = down && !up;

	Walk = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);

	Shoot = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	Look = RenderUtils::ScreenToWorld(Vector2<double>(mousePos.x, mousePos.y));
}
