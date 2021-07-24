#include "Map.h"

Map::Map(std::string Name)
{
	this->Name = Name;
}

void Map::Load()
{
	Blocks.push_back(new Block(0, 52, 51, 1, false, sf::Color(94, 94, 94)));
	Blocks.push_back(new Block(0, -52, 51, 1, false, sf::Color(94, 94, 94)));
	Blocks.push_back(new Block(-52, 0, 1, 51, false, sf::Color(94, 94, 94)));
	Blocks.push_back(new Block(52, 0, 1, 51, false, sf::Color(94, 94, 94)));
}

void Map::UnLoad()
{
	for (unsigned int i = 0; i < Blocks.size(); i++)
	{
		delete Blocks[i];
		Blocks.erase(Blocks.begin() + i);
		i--;
	}
}

std::string Map::getName()
{
	return Name;
}
