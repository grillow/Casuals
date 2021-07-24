#pragma once
#include "Vector2.h"
#include "EntityManager.h"

class Ray
{
private:
	Vector2<double> Intersect(Vector2<double> p1, Vector2<double> p2);
	void CutByLineSegment(Vector2<double> p1, Vector2<double> p2);
	void CutByEntity(Entity* entity);
	double Distance;
public:
	Ray(Vector2<double> start, Vector2<double> direction, double Distance);
	Vector2<double> start;
	Vector2<double> end;
	Vector2<double> Cast(Entity* exception);
};
