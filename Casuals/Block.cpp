#include "Block.h"
#include "RenderUtils.h"

Block::Block(double X, double Y, double Width, double Height, bool Movable, sf::Color color)
{
	this->Position = Vector2<double>(X, Y);
	this->Width = Width;
	this->Height = Height;
	this->Movable = Movable;
	this->color = color;
}

Block::Block(Vector2<double> Position, double Width, double Height, bool Movable, sf::Color color)
{
	this->Position = Position;
	this->Width = Width;
	this->Height = Height;
	this->Movable = Movable;
	this->color = color;
}

void Block::Update(float elapsed)
{

}

void Block::Draw()
{
	RenderUtils::DrawRect(Position, Width, Height, color);
}
