#include "FileUtils.h"

std::string FileUtils::ReadFile(std::string filePath)
{
	std::string fileContents = "";
	std::ifstream inFile;

	inFile.open(filePath);
	char ch;

	while (inFile.get(ch))
	{
		fileContents += ch;
	}

	inFile.close();

	return fileContents;
}


void FileUtils::WriteFile(std::string filePath, std::string content)
{
	std::ofstream outFile;

	outFile.open(filePath);
	outFile << content;
	outFile.close();
}
