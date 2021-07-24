#pragma once
#include <vector>
#include "Map.h"

class MapManager
{
private:
	std::vector<Map*> MapList;
	unsigned int i = 0;
public:
	MapManager();
	void UnLoad();
	void Load(int i);
	void LoadPrev();
	void LoadNext();
};
