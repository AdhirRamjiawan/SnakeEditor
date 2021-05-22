
#include "GameState.h"

ConfigModel GameState::Config;

GameState::GameState()
{
	Reset();

	GameState::Config.PlayMusic = false; // TODO: change this to true for release
	GameState::Config.PlaySfx = false; // TODO: change this to true for release
	GameState::Config.DisplayGrid = false;
}

void GameState::Reset()
{
	PlayerScore = 0;
}

GameState::~GameState()
{
}