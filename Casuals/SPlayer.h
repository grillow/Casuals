#pragma once
#include "Entity.h"
#include "GameInput.h"
#include <SFML/Graphics.hpp>

class SPlayer : public Entity
{
private:
	double speed;
	double WalkMultiplier;
	bool ShootPressed = false;
	sf::Clock ShootClock;
	double FireRate;
public:
	SPlayer();
	Vector2<double> Look;
	void GetInput(GameInput* Input);
	void Update(float elapsed) override;
	void Draw() override;
};
