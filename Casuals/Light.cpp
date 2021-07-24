#include "Light.h"
#include "Ray.h"
#include "CollidableRectangle.h"


void Light::SortRayCasts(Vector2<double> start, std::vector<Vector2<double>>* rays)
{
	std::vector<Vector2<double>> rez;

	for (unsigned int i = 0; i < rays->size(); i++)
	{
		unsigned int mi = 0;
		double m = ((*rays)[mi] - start).Angle();

		for (unsigned int j = 1; j < rays->size(); j++)
		{
			if (((*rays)[j] - start).Angle() < m)
			{
				mi = j;
				m = ((*rays)[j] - start).Angle();
			}
		}
		rez.push_back((*rays)[mi]);
		rays->erase(rays->begin() + mi);
		i--;
	}

	*rays = rez;
}

int Light::Partition(Vector2<double> start, std::vector<Vector2<double>>* rays, int l, int h)
{
	Vector2<double> x = (*rays)[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (((*rays)[j] - start).Angle() <= (x - start).Angle())
		{
			i++;

			Vector2<double> temp = (*rays)[i];
			(*rays)[i] = (*rays)[j];
			(*rays)[j] = temp;
		}
	}

	Vector2<double> temp = (*rays)[i + 1];
	(*rays)[i + 1] = (*rays)[h];
	(*rays)[h] = temp;

	return (i + 1);
}

void Light::SortRays(Vector2<double> start, std::vector<Vector2<double>>* rays, int l, int h)
{
	if (l < h)
	{
		int p = Partition(start, rays, l, h);
		SortRays(start, rays, l, p - 1);
		SortRays(start, rays, p + 1, h);
	}
}

void Light::LightStupid(SPlayer* source)
{
	std::vector<Vector2<double>> RayCastResults;

	const int amount = 1440;
	double FOV = PI * 3 / 4;
	double angle = (source->Look - source->Position).Angle();

	for (double a = angle - FOV / 2; a < angle + FOV / 2; a += (FOV) / amount)
	{
		Ray ray(source->Position, Vector2<double>(cos(a), sin(a)), 250);
		Vector2<double> rez = ray.Cast(source);
		RayCastResults.push_back(rez);
	}

	for (unsigned int i = 0; i < RayCastResults.size() - 1; i++)
	{
		RenderUtils::DrawTriangle(source->Position, RayCastResults[i], RayCastResults[i + 1], sf::Color(255, 255, 255, 169));
	}
}

void Light::LightUp(SPlayer* source)
{
	std::vector<Vector2<double>> RayCastResults;
	Vector2<double> pos = source->Position;

	for (unsigned int i = 0; i < EntityManager::EntityList.size(); i++)
	{
		Entity* entity = EntityManager::EntityList[i];
		if (entity == source)
			continue;

		//Base eight raycasts
		for (double a = 0; a <= 2 * PI; a += 2 * PI / 8)
		{
			Ray ray(source->Position, Vector2<double>(cos(a), sin(a)), 250);
			Vector2<double> rez = ray.Cast(source);
			RayCastResults.push_back(rez);
		}
		
		//For every edge of the entity
		CollidableRectangle rect(entity->Position, entity->Width, entity->Height);
		for (int i = 0; i < 4; i++)
		{
			const double appr = 0.005 * PI / 180;

			Vector2<double> dot = rect.Dots[i];
			double ang = (dot - pos).Angle();

			Vector2<double> direction1(cos(ang - appr), sin(ang - appr));
			Ray ray1(pos, direction1, 250);
			RayCastResults.push_back(ray1.Cast(source));

			Vector2<double> direction2 = Vector2<double>(cos(ang + appr), sin(ang + appr));
			Ray ray2(pos, direction2, 250);
			RayCastResults.push_back(ray2.Cast(source));
		}

	}

	SortRays(pos, &RayCastResults, 0, RayCastResults.size() - 1);

	for (unsigned int i = 0; i < RayCastResults.size(); i++)
	{
		RenderUtils::DrawTriangle(source->Position, RayCastResults[i], RayCastResults[(i + 1) % RayCastResults.size()], sf::Color(255, 255, 255, 168));
	}

}
