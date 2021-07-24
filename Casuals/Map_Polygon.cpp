#include "Map_Polygon.h"

void Map_Polygon::Load()
{
	Map::Load();
	Blocks.push_back(new Block(4.5, -3, 1.5f, 4, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-17, 25, 10, 3, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(13, 19.5, 10, 2.5f, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-40, -5, 1, 3, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-5, -30, 3, 3, false, sf::Color(245, 169, 5)));

	Blocks.push_back(new Block(-30, -30, 8, 3, true, sf::Color(236, 245, 66)));
	Blocks.push_back(new Block(+30, -30, 2, 13, true, sf::Color(236, 245, 66)));
}
