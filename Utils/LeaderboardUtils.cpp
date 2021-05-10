#include "LeaderboardUtils.h"

std::vector<std::string> LeaderboardUtils::Load()
{
	std::vector<std::string> entries;
	auto data = FileUtils::ReadFile(FILE_LEADERBOARD);
	std::string temp = "";

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == '|')
		{
			entries.push_back(temp);
			temp = "";
			continue;
		}

		temp += data[i];
	}

	entries.push_back(temp);
	temp = "";

	return entries;
}

void LeaderboardUtils::Save(std::vector<std::string> entries)
{
	std::string data = "";

	for (auto entry : entries)
	{
		data += entry + "|";
	}

	// remove trailing delimiter
	data = data.substr(0, data.size() - 1);

	FileUtils::WriteFile(FILE_LEADERBOARD, data);
}
