#pragma once
#include "Vector2.h"

class CollidableRectangle
{
private:
	Vector2<double> Position;
	
	bool CDots[4];
	double Width;
	double Height;
	Vector2<double> PushOut(CollidableRectangle rect);
public:
	CollidableRectangle(Vector2<double> Position, double Width, double Height);
	Vector2<double> Dots[4];
	bool Collides(CollidableRectangle rect);
	Vector2<double> Collide(CollidableRectangle rect);
	bool ContainsPoint(Vector2<double> point);
	bool ApproximatelyContainsPoint(Vector2<double> point, double radius);
};
