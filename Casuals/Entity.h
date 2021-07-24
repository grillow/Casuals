#pragma once
#include "Vector2.h"
#include "EntityManager.h"

class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update(float elapsed) = 0;
	virtual void Draw() = 0;

	double Width = 0;
	double Height = 0;
	Vector2<double> Position;
	Vector2<double> Velocity;
};
