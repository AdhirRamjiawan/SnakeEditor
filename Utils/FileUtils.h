#pragma once

#include <iostream>
#include <fstream>

class FileUtils
{
public:
	static std::string ReadFile(std::string filePath);
	static void WriteFile(std::string filePath, std::string content);
};
