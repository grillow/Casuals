#include "CollidableRectangle.h"
#include "Entity.h"
#include <algorithm>

Vector2<double> CollidableRectangle::PushOut(CollidableRectangle rect)
{
	Vector2<double> S(0, 0);

	double right = Position.X + Width - (rect.Position.X - rect.Width);
	double bottom = Position.Y - Height - (rect.Position.Y + rect.Height);
	double left = Position.X - Width - (rect.Position.X + rect.Width);
	double top = Position.Y + Height - (rect.Position.Y - rect.Height);

	double mmax = -std::max(std::max(right, left), std::max(top, bottom));
	double mmin = -mmax;

	if (left < 0)
		mmax = std::max(mmax, left);
	if (right > 0)
		mmin = std::min(mmin, right);
	if (bottom < 0)
		mmax = std::max(mmax, bottom);
	if (top > 0)
		mmin = std::min(mmin, top);

	if (mmin < std::abs(mmax))
	{
		if (right == mmin)
			S.X = -mmin;
		if (top == mmin)
			S.Y = -mmin;
	}
	else if (mmin > std::abs(mmax))
	{
		if (left == mmax)
			S.X = -mmax;
		if (bottom == mmax)
			S.Y = -mmax;
	}
	return S;
}

CollidableRectangle::CollidableRectangle(Vector2<double> Position, double Width, double Height)
{
	this->Position = Position;
	this->Width = Width;
	this->Height = Height;
	Dots[0] = Position + Vector2<double>(-Width, -Height);
	Dots[1] = Position + Vector2<double>(-Width, +Height);
	Dots[2] = Position + Vector2<double>(+Width, +Height);
	Dots[3] = Position + Vector2<double>(+Width, -Height);
}

bool CollidableRectangle::Collides(CollidableRectangle rect)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		Vector2<double> dot = Dots[i];
		CDots[i] = (
				dot.X > rect.Position.X - rect.Width &&
				dot.X < rect.Position.X + rect.Width &&
				dot.Y > rect.Position.Y - rect.Height &&
				dot.Y < rect.Position.Y + rect.Height );
	}
	return CDots[0] || CDots[1] || CDots[2] || CDots[3];
}

Vector2<double> CollidableRectangle::Collide(CollidableRectangle rect)
{
	if (Collides(rect) || rect.Collides(*this))
		return PushOut(rect);
	return Vector2<double>(0, 0);
}

bool CollidableRectangle::ContainsPoint(Vector2<double> point)
{
	return (Position.X - Width <= point.X && point.X <= Position.X + Width && Position.Y - Height <= point.Y && point.Y <= Position.Y + Height);
}

bool CollidableRectangle::ApproximatelyContainsPoint(Vector2<double> point, double radius)
{
	return (Position.X - Width - radius <= point.X && point.X <= Position.X + Width + radius && Position.Y - Height - radius <= point.Y && point.Y <= Position.Y + Height + radius);
}
