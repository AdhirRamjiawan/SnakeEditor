#include "LevelUtils.h"

LevelUtils::LevelUtils()
{
}

LevelUtils::~LevelUtils()
{
}

struct LevelModel LevelUtils::GetLevel(std::string name)
{
	std::vector<std::string> levelEntries = getLevelDataEntries(name);
	struct LevelModel model;

	processEntries(&levelEntries, &model);

	return model;
}

void LevelUtils::processEntries(std::vector<std::string> *entries, struct LevelModel *model)
{
	model->Name = "(<[ ?? LEVEL ?? ]>)";
	model->Player = struct PlayerModel();
	model->WinCount = 9999;

	for (auto entry : *entries)
	{
		auto nameFound = StringUtils::StartsWith(entry, "name");
		auto playerFound = StringUtils::StartsWith(entry, "player");
		auto winFound = StringUtils::StartsWith(entry, "win");

		if (nameFound)
		{
			model->Name = parseName(entry);
		}
		else if (playerFound)
		{
			model->Player = parsePlayer(entry);
		}
		else if (winFound)
		{
			model->WinCount = parseWin(entry);
		}
	}
}

int LevelUtils::parseWin(std::string entry)
{
	std::vector<std::string> parts = StringUtils::Split(entry, " ");
	int result = std::stoi(parts[1]);
	return result;
}

struct PlayerModel LevelUtils::parsePlayer(std::string entry)
{
	struct PlayerModel player {};
	std::vector<std::string> parts = StringUtils::Split(entry, " ");

	player.PositionX = std::stoi(parts[1]);
	player.PositionY = std::stoi(parts[2]);

	return player;
}

std::string LevelUtils::parseName(std::string entry)
{
	return entry.substr(StringUtils::IndexOf(entry, " "));
}

std::vector<std::string> LevelUtils::getLevelDataEntries(std::string name)
{
	std::string levelData = FileUtils::ReadFile("Levels\\" + name);
	std::vector<std::string> entries;

	std::string temp = "";

	for (int i = 0; i < levelData.size(); i++)
	{
		if (levelData[i] == '|')
		{
			temp = StringUtils::Replace(temp, "\n", "");
			temp = StringUtils::Trim(temp);
			entries.push_back(temp);
			temp = "";
			continue;
		}

		temp += levelData[i];
	}

	temp = StringUtils::Replace(temp, "\n", "");
	temp = StringUtils::Trim(temp);
	entries.push_back(temp);

	return entries;
}