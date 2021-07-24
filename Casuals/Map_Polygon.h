#pragma once
#include "Map.h"
class Map_Polygon : public Map
{
public:
	Map_Polygon() : Map("Polygon") {}
	void Load();
};
