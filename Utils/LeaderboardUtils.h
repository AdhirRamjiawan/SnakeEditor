#pragma once

#include <vector>
#include <string>
#include "FileUtils.h"
#include "FileNames.h"

class LeaderboardUtils
{
public:
	static std::vector<std::string> Load();
	static void Save(std::vector<std::string>);
};