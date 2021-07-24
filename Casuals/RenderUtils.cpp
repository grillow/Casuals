#include "RenderUtils.h"
#include "Ray.h"
#include "CollidableRectangle.h"


double RenderUtils::Scale;
int RenderUtils::scrWidth;
int RenderUtils::scrHeight;
const int RenderUtils::MAX_FPS = 60;
float RenderUtils::MS_PER_FRAME = 1000 / RenderUtils::MAX_FPS;
int RenderUtils::FPS = 0;
sf::RenderWindow* RenderUtils::window;


void RenderUtils::Init()
{
	scrWidth = sf::VideoMode::getDesktopMode().width;
	scrHeight = sf::VideoMode::getDesktopMode().height;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 16;
	window = new sf::RenderWindow(sf::VideoMode(scrWidth, scrHeight), "Casuals", sf::Style::Fullscreen, settings);
	window->setVerticalSyncEnabled(true);
	CalculateScale();
}

Vector2<double> RenderUtils::WorldToScreen(Vector2<double> vec)
{
	vec.X = scrWidth/2 + getScaled(vec.X);
	vec.Y = scrHeight/2 - getScaled(vec.Y);
	return vec;
}

Vector2<double> RenderUtils::ScreenToWorld(Vector2<double> vec)
{
	vec.X = getUnScaled(vec.X - scrWidth / 2);
	vec.Y = getUnScaled(-vec.Y + scrHeight / 2);
	return vec;
}

sf::RectangleShape RenderUtils::WorldRectToScreenRect(Vector2<double> vec, double Width, double Height)
{
	Vector2<double> scaledPos = WorldToScreen(vec);
	scaledPos -= Vector2<double>(getScaled(Width), getScaled(Height));
	sf::Vector2f pos(scaledPos.X, scaledPos.Y);
	sf::RectangleShape rect(sf::Vector2f(getScaled(2*Width), getScaled(2*Height)));
	rect.setPosition(pos);
	return rect;
}

void RenderUtils::CalculateScale()
{
	Scale = std::min(scrWidth, scrHeight) / 100;
}

double RenderUtils::getScaled(double var)
{
	return var * Scale;
}

double RenderUtils::getUnScaled(double var)
{
	return var / Scale;
}

Vector2<double> RenderUtils::getScaled(Vector2<double> vec)
{
	return Vector2<double>(getScaled(vec.X), getScaled(vec.Y));
}

Vector2<double> RenderUtils::getUnScaled(Vector2<double> vec)
{
	return Vector2<double>(getUnScaled(vec.X), getUnScaled(vec.Y));
}

void RenderUtils::DrawRect(Vector2<double> Position, double Width, double Height, sf::Color color)
{
	sf::RectangleShape rect = WorldRectToScreenRect(Position, Width, Height);
	rect.setFillColor(color);
	window->draw(rect);
}

void RenderUtils::DrawCircle(Vector2<double> Position, double Radius, sf::Color color)
{
	sf::CircleShape circle(getScaled(Radius));
	circle.setPosition(sf::Vector2f(WorldToScreen(Position).X - getScaled(Radius), WorldToScreen(Position).Y - getScaled(Radius)));
	circle.setFillColor(color);
	window->draw(circle);
}

void RenderUtils::DrawTriangle(Vector2<double> p1, Vector2<double> p2, Vector2<double> p3, sf::Color color)
{
	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	p1 = WorldToScreen(p1);
	p2 = WorldToScreen(p2);
	p3 = WorldToScreen(p3);
	triangle.setPoint(0, sf::Vector2f(p1.X, p1.Y));
	triangle.setPoint(1, sf::Vector2f(p2.X, p2.Y));
	triangle.setPoint(2, sf::Vector2f(p3.X, p3.Y));
	triangle.setFillColor(color);
	window->draw(triangle);
}

void RenderUtils::DrawLine(Vector2<double> pos1, Vector2<double> pos2, sf::Color color)
{
	sf::Vertex line[2];
	line[0].position = sf::Vector2f(pos1.X, pos1.Y);
	line[1].position = sf::Vector2f(pos2.X, pos2.Y);
	line[0].color = color;
	line[1].color = color;
	window->draw(line, 2, sf::Lines);
}

void RenderUtils::DrawScaledLine(Vector2<double> pos1, Vector2<double> pos2, sf::Color color)
{
	pos1 = Vector2<double>(getScaled(pos1.X), -getScaled(pos1.Y)) + Vector2<double>(scrWidth / 2, scrHeight / 2);
	pos2 = Vector2<double>(getScaled(pos2.X), -getScaled(pos2.Y)) + Vector2<double>(scrWidth / 2, scrHeight / 2);
	DrawLine(pos1, pos2, color);
}

void RenderUtils::DrawGrid(double step, sf::Color color)
{
	for (double i = 0; i < getUnScaled(scrWidth); i+=step)
	{
		DrawLine(Vector2<double>(getScaled(i), 0), Vector2<double>(getScaled(i), scrHeight), color);
	}
	for (double i = 0; i < getUnScaled(scrHeight); i+=step)
	{
		DrawLine(Vector2<double>(0, getScaled(i)), Vector2<double>(scrWidth, getScaled(i)), color);
	}
}
