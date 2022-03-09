
#include "GameState.h"

ConfigModel GameState::Config;

GameState::GameState()
{
	Reset();

	GameState::Config.PlayMusic = true; // TODO: change this to true for release
	GameState::Config.PlaySfx = true; // TODO: change this to true for release
	GameState::Config.DisplayGrid = false;
}

void GameState::Reset()
{
	PlayerScore = 0;
	LevelComplete = false;
}

GameState::~GameState()
{
}