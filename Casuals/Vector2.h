#pragma once
#include <math.h>
const double PI = 3.14159265359;

template <class T>
class Vector2
{
public:
	T X, Y;

	Vector2 ()
	{
		this->X = 0;
		this->Y = 0;
	}

	Vector2 (T X, T Y)
	{
		this->X = X;
		this->Y = Y;
	}

	void Set(T X, T Y)
	{
		this->X = X;
		this->Y = Y;
	}

	Vector2& operator= (const Vector2& vec)
	{
		X = vec.X;
		Y = vec.Y;
		return *this;
	}

	Vector2 operator+ (Vector2 vec)
	{
		return Vector2(X + vec.X, Y + vec.Y);
	}

	Vector2 operator- (Vector2 vec)
	{
		return Vector2(X - vec.X, Y - vec.Y);
	}

	Vector2 operator+= (Vector2 vec)
	{
		X += vec.X;
		Y += vec.Y;
		return *this;
	}

	Vector2 operator-= (Vector2 vec)
	{
		X -= vec.X;
		Y -= vec.Y;
		return *this;
	}

	Vector2 operator* (T M)
	{
		return Vector2(X * M, Y * M);
	}

	Vector2 operator/ (T M)
	{
		return Vector2(X / M, Y / M);
	}

	Vector2 operator*= (T M)
	{
		X *= M;
		Y *= M;
		return *this;
	}

	Vector2 operator/= (T M)
	{
		X /= M;
		Y /= M;
		return *this;
	}

	bool operator== (Vector2 vec)
	{
		return (X == vec.X && Y == vec.Y);
	}

	bool operator!= (Vector2 vec)
	{
		return (X != vec.X || Y != vec.Y);
	}

	Vector2 Normalize()
	{
		double mag = this->Magnitude();
		if (mag != 0)
		{
			this->X /= mag;
			this->Y /= mag;
		}
		return *this;
	}

	double Magnitude()
	{
		return sqrt(X * X + Y * Y);
	}

	Vector2 SetMagnitude(T M)
	{
		Normalize();
		this->X *= M;
		this->Y *= M;
		return *this;
	}

	double Angle()
	{
		double ang = atan2(X, Y);
		if (ang < 0)
			ang += 2 * PI;
		return -ang + PI/2;
	}

	bool ApproximatelyEquals(Vector2 vec, T radius)
	{
		return ((vec - *this).Magnitude() <= radius);
	}

	static T Dot(Vector2 v1, Vector2 v2)
	{
		return v1.X * v2.X + v1.Y * v2.Y;
	}

};
