#pragma once
#include "Vector2.h"

class GameInput
{
public:
	bool Up;
	bool Down;
	bool Left;
	bool Right;
	bool Walk;
	bool Shoot;
	Vector2<double> Look;

	void Update();
};
