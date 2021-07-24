#include "MapManager.h"
#include "Map_Polygon.h"
#include "Map_Josh.h"
#include "Map_Duel.h"
#include <algorithm>

MapManager::MapManager()
{
	MapList.push_back(new Map_Polygon());
	MapList.push_back(new Map_Josh());
	MapList.push_back(new Map_Duel());
}

void MapManager::UnLoad()
{
	MapList[i]->UnLoad();
}

void MapManager::Load(int i)
{
	UnLoad();
	MapList[i]->Load();
}

void MapManager::LoadPrev()
{
	UnLoad();
	i = std::max( (unsigned int)0, i - 1);
	Load(i);
}

void MapManager::LoadNext()
{
	UnLoad();
	i = std::min( (unsigned int)MapList.size() - 1, i + 1);
	Load(i);
}
