
#pragma once

#include <SFML/Window.hpp>

class GameState
{
public:
	GameState();
	~GameState();
	void Reset();
	int PlayerScore = 0;
	static const int GameWidth = 520;
	static const int GameHeight = 400;

private:
	
};
