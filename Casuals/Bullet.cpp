#include "Bullet.h"
#include "RenderUtils.h"

Bullet::Bullet(Vector2<double> Position, double speed, Vector2<double> Direction)
{
	Width = 0.15f;
	Height = 0.15f;
	this->speed = speed;
	Direction.Normalize();
	this->Position = Position + Direction;
	Direction.SetMagnitude(speed);
	Velocity = Direction;
}

void Bullet::Update(float elapsed)
{
	Position += Velocity * elapsed;
}

void Bullet::Draw()
{
	RenderUtils::DrawCircle(Position, Width, sf::Color(227, 20, 20));
}
