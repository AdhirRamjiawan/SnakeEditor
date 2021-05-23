
#pragma once

#include "Config.h"
#include <SFML/Window.hpp>

class GameState
{
public:
	GameState();
	~GameState();
	void Reset();
	int PlayerScore = 0;
	bool LevelComplete = false;
	static const int GameWidth = 520;
	static const int GameHeight = 400;
	static struct ConfigModel Config;

private:
	
};
