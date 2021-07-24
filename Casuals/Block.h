#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Block : public Entity
{
private:
	sf::Color color;
public:
	Block(double X, double Y, double Width, double Height, bool Movable, sf::Color color);
	Block(Vector2<double> Position, double Width, double Height, bool Movable, sf::Color color);
	bool Movable;
	void Update(float elapsed) override;
	void Draw() override;
};
