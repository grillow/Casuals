#pragma once
#include "Block.h"
#include <vector>
#include <string>

class Map
{
protected:
	std::vector<Block*> Blocks;
	std::string Name;

public:
	Map(std::string Name);
	virtual void Load();
	void UnLoad();
	std::string getName();
};
