#pragma once
#include "Vector2.h"
#include "EntityManager.h"
#include "SPlayer.h"
#include "RenderUtils.h"

class Light
{
private:
	static void SortRayCasts(Vector2<double> start, std::vector<Vector2<double>>* rays);

	static int Partition(Vector2<double> start, std::vector<Vector2<double>>* rays, int l, int h);
	static void SortRays(Vector2<double> start, std::vector<Vector2<double>>* rays, int l, int h);
public:
	static void LightStupid(SPlayer* source);
	static void LightUp(SPlayer* source);
};
