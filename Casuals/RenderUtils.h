#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "EntityManager.h"
#include "SPlayer.h"

class SPlayer;

class RenderUtils
{
private:
	static double Scale;
	static void CalculateScale();

public:
	static int scrWidth;
	static int scrHeight;
	static const int MAX_FPS;
	static float MS_PER_FRAME;
	static int FPS;
	static sf::RenderWindow* window;
	
	static void Init();

	static Vector2<double> WorldToScreen(Vector2<double> vec);
	static Vector2<double> ScreenToWorld(Vector2<double> vec);
	static sf::RectangleShape WorldRectToScreenRect(Vector2<double> vec, double Width, double Height);
	static double getScaled(double var);
	static double getUnScaled(double var);
	static Vector2<double> getScaled(Vector2<double> vec);
	static Vector2<double> getUnScaled(Vector2<double> vec);
	static void DrawRect(Vector2<double> Position, double Width, double Height, sf::Color color);
	static void DrawCircle(Vector2<double> Position, double Radius, sf::Color color);
	static void DrawTriangle(Vector2<double> p1, Vector2<double> p2, Vector2<double> p3, sf::Color color);
	static void DrawLine(Vector2<double> pos1, Vector2<double> pos2, sf::Color color);
	static void DrawScaledLine(Vector2<double> pos1, Vector2<double> pos2, sf::Color color);
	static void DrawGrid(double step, sf::Color color);


};
