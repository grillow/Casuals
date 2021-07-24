#pragma once
#include "Vector2.h"
#include "Entity.h"

class RayCast
{
private:
	Vector2<double> LineIntersection(Vector2<double> p1, Vector2<double> p2);
	void GetCutByEntity(Entity* entity);
	Entity* owner;
public:
	RayCast(Entity* owner, Vector2<double> direction);
	Vector2<double> start;
	Vector2<double> exception;
	Vector2<double> rez;
	Vector2<double> end;
	void GetCut();
};
