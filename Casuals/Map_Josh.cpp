#include "Map_Josh.h"

void Map_Josh::Load()
{
	Map::Load();
	Blocks.push_back(new Block(-5, 7, 3, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(5, 7, 3, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(0, 11, 16, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(0, 13, 12, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-13, 2, 1, 8, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(13, 2, 1, 8, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-10, 34, 1, 13, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(10, 34, 1, 13, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-33, 18, 13, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(33, 18, 13, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(13, -30, 1, 1, false, sf::Color(245, 169, 5)));
	Blocks.push_back(new Block(-13, -30, 1, 1, false, sf::Color(245, 169, 5)));
}
 