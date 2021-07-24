#include "SPlayer.h"
#include "RenderUtils.h"
#include "Bullet.h"

void SPlayer::GetInput(GameInput* Input)
{
	int x = ((int)Input->Right - (int)Input->Left);
	int y = ((int)Input->Up - (int)Input->Down);
	Velocity.Set(x, y);
	Velocity.SetMagnitude(speed);
	if (Input->Walk)
		Velocity *= WalkMultiplier;
	ShootPressed = Input->Shoot;
	Look = Input->Look;
}

SPlayer::SPlayer()
{
	speed = 17;
	WalkMultiplier = 0.25;
	Width = 1;
	Height = 1;
	FireRate = 5;
}

void SPlayer::Update(float elapsed)
{
	Position += Velocity * elapsed;
	if (ShootPressed && ShootClock.getElapsedTime().asSeconds() >= 1/FireRate)
	{
		Bullet* b = new Bullet(Position, 50, Look - Position);
		ShootClock.restart();
	}
}

void SPlayer::Draw()
{
	RenderUtils::DrawLine(RenderUtils::WorldToScreen(Position), RenderUtils::WorldToScreen(Look), sf::Color(224, 9, 9, 255));
	RenderUtils::DrawRect(Position, Width, Height, sf::Color(200, 66, 245));
}
