#pragma once
#include "Entity.h"
#include "RenderUtils.h"

class LightSource : public Entity
{
private:

public:
	LightSource(Vector2<double> Position, Vector2<double> Direction, double FOV, sf::Color color);
	Vector2<double> Look;
	double FOV;
	sf::Color color;
	void Update(float elapsed) override;
	void Draw() override;
};
