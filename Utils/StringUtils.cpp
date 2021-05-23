#include "StringUtils.h"

// THIS IS A MESS SINCE I NEEDED TO COPY FROM THE C PROJECT NAGARI : https://github.com/AdhirRamjiawan/nagari/blob/master/nagari.c
// AND NEW IMPLEMENTATIONS FOR SOME METHODS

bool StringUtils::Contains(std::string string1, std::string string2)
{
	bool result = false;

	if (strstr(string1.c_str(), string2.c_str()) != NULL)
		result = true;

	return result;
}

bool StringUtils::EndsWith(std::string string1, std::string string2)
{
	return false;
}

int StringUtils::IndexOf(std::string string1, std::string string2)
{
	int index = -1;
	char* ptr = (char *)strstr(string1.c_str(), string2.c_str());

	if (ptr != NULL)
		index = ptr - string1.c_str();

	return index;
}

std::string StringUtils::ToLower(std::string string)
{
	return std::string();
}

std::string StringUtils::ToUpper(std::string string)
{
	return std::string();
}

void StringUtils::Insert(std::string string1, std::string string2)
{
}

int StringUtils::LastIndexOf(std::string string1, std::string string2)
{
	return 0;
}

std::string StringUtils::Replace(std::string string1, std::string string2, std::string string3)
{
	std::string result;
	int index = StringUtils::IndexOf(string1, string2);

	if (index > 0)
	{
		// split these into multiple lines with meaningful variable names
		std::string temp = string1.substr(0, index - 1) + string3 + string1.substr(index + string2.size(), string1.size() - index + string2.size());
		return StringUtils::Replace(temp, string2, string3);
	}

	return string1;
}

std::vector<std::string> StringUtils::Split(std::string string1, std::string string2)
{
	std::vector<std::string> results;
	int index = StringUtils::IndexOf(string1, string2);
	std::string temp = string1;

	do
	{
		std::string remainder = temp.substr(index + 1, temp.size() - index);
		temp = temp.substr(0, index);
		results.push_back(temp);
		
		index = StringUtils::IndexOf(remainder, string2);
		temp = remainder;
	}
	while (index > 0);

	results.push_back(temp);

	return results;
}

bool StringUtils::StartsWith(std::string string1, std::string string2)
{
	bool result = false;

	int len = string1.size();
	int len2 = string2.size();
	int count = 0;

	char* s1 = (char *)string1.c_str();
	char* s2 = (char *)string2.c_str();

	while (*s1 == *s2)
	{
		s1++;
		s2++;
		count++;
	}

	if (count >= len2)
		result = true;

	return result;
}

std::string StringUtils::Trim(std::string string1)
{
    std::string result;
    char* raw_str;
    char* ptr_raw;
    char* ptr;
    char* ptr_start;
    char* ptr_end;
	char* s1 = (char *)string1.c_str();
    int len;

    len = string1.size();
    ptr = (char *)string1.c_str();

    // find the start
    while (*s1 == ' ')
        s1++;

    ptr_start = s1;

    // go to the end
    while (*s1 != '\0')
        s1++;

    // move away from '\0'
    s1--;

    // find the end
    while (*s1 == ' ')
        s1--;

    ptr_end = s1;

    // copy between start to end pointers
    while (ptr_start <= ptr_end)
        result += *ptr_start++;

    s1 = ptr;

    return result;
}
