#pragma once

#include "FileUtils.h"
#include "../State/Level.h"
#include "StringUtils.h"

#include <string>
#include <vector>

class LevelUtils
{
public:
	LevelUtils();
	~LevelUtils();
	static struct LevelModel GetLevel(std::string name);

private:
	static std::vector<std::string> getLevelDataEntries(std::string name);
	static void processEntries(std::vector<std::string>* entries, LevelModel* model);
	static int parseWin(std::string entry);
	static PlayerModel parsePlayer(std::string entry);
	static std::string parseName(std::string entry);
};