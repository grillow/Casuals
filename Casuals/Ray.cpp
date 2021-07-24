#include "Ray.h"
#include "CollidableRectangle.h"
#include "RenderUtils.h"

Vector2<double> Ray::Intersect(Vector2<double> p1, Vector2<double> p2)
{
	double x1 = start.X;
	double x2 = end.X;
	double x3 = p1.X;
	double x4 = p2.X;
	double y1 = start.Y;
	double y2 = end.Y;
	double y3 = p1.Y;
	double y4 = p2.Y;

	//double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4));
	double u = -(((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)));
	double X = x3 + u * (x4 - x3);
	double Y = y3 + u * (y4 - y3);

	Vector2<double> result(X, Y);
	return result;
}

void Ray::CutByLineSegment(Vector2<double> p1, Vector2<double> p2)
{
	Vector2<double> Intersection = Intersect(p1, p2);
	Vector2<double> pos = (p1 + p2) / 2;
	double Width = abs(p2.X - pos.X);
	double Height = abs(p2.Y - pos.Y);
	CollidableRectangle rect(pos, Width, Height);
	Vector2<double> deltaNew = Intersection - start;
	Vector2<double> deltaOld = end - start;
	if (rect.ApproximatelyContainsPoint(Intersection, 0.000005)
		&& deltaNew.Magnitude() < deltaOld.Magnitude()
		&& Vector2<double>::Dot(deltaNew, deltaOld) > 0)
	{
		end = Intersection;
	}
}

void Ray::CutByEntity(Entity* entity)
{
	CollidableRectangle eRect(entity->Position, entity->Width, entity->Height);

	Vector2<double>* point = eRect.Dots;
	
	Vector2<double> Li[4];
	Li[0] = Intersect(point[0], point[1]);
	Li[1] = Intersect(point[1], point[2]);
	Li[2] = Intersect(point[2], point[3]);
	Li[3] = Intersect(point[3], point[0]);

	for (int i = 0; i < 4; i++)
	{
		Vector2<double> deltaNew = Li[i] - start;
		Vector2<double> deltaOld = end - start;
		if ( deltaNew.Magnitude() < deltaOld.Magnitude() && eRect.ContainsPoint(Li[i]) )
		{
			deltaNew.Normalize();
			deltaOld.Normalize();
			if (Vector2<double>::Dot(deltaNew, deltaOld) > 0)
			{
				end = Li[i];
			}
			
		}
	}
}

Ray::Ray(Vector2<double> start, Vector2<double> direction, double Distance)
{
	this->start = start;
	this->end = start + direction.SetMagnitude(Distance);
	this->Distance = Distance;
}

Vector2<double> Ray::Cast(Entity* exception)
{
	for (unsigned int i = 0; i < EntityManager::EntityList.size(); i++)
	{
		Entity* entity = EntityManager::EntityList[i];
		if (entity != exception)
			CutByEntity(entity);
	}
	return end;
}
