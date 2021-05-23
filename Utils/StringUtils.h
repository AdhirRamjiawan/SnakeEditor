#pragma once

#include <vector>
#include <string>

class StringUtils
{
public:
	static bool Contains(std::string string1, std::string string2);
	static bool EndsWith(std::string string1, std::string string2);
	static int IndexOf(std::string string1, std::string string2);
	static std::string ToLower(std::string string);
	static std::string ToUpper(std::string string);
	static void Insert(std::string string1, std::string string2);
	static int LastIndexOf(std::string string1, std::string string2);
	static std::string Replace(std::string string1, std::string string2, std::string string3);
	static std::vector<std::string> Split(std::string string1, std::string string2);
	static bool StartsWith(std::string string1, std::string string2);
	static std::string Trim(std::string string1);

private:

};