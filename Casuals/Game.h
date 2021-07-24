#pragma once
#include <SFML/Graphics.hpp>
#include "GameInput.h"
#include "SPlayer.h"
#include "MapManager.h"

class Game
{
private:
	void MainLoop();
	void ProcessEvents();
	void Update(float deltaTime);
	void Logic(float deltaTime);
	void Render();

	GameInput Input;
	SPlayer Player;
	MapManager mapManager;

public:
	void Run();
};
