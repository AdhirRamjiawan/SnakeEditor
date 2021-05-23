#pragma once

struct PlayerModel
{
	int PositionX;
	int PositionY;
};

struct LevelModel {
	std::string Name;
	struct PlayerModel Player;
};
