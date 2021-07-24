#include "LightSource.h"
#include "RenderUtils.h"

LightSource::LightSource(Vector2<double> Position, Vector2<double> Direction, double FOV, sf::Color color)
{
	this->Position = Position;
	this->Look = Position + Direction;
	this->FOV = FOV;
	this->color = color;
}

void LightSource::Update(float elapsed)
{

}

void LightSource::Draw()
{
	///TODO: fix, wtf is this?
	// RenderUtils::LightStupid(this);
}
