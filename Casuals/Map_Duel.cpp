#include "Map_Duel.h"

void Map_Duel::Load()
{
	Map::Load();
	Blocks.push_back(new Block(0, 0, 4, 4, false, sf::Color(242, 165, 70)));
}
