#pragma once

#include <SFML/Graphics.hpp>

class TextUtils
{
public:
	static sf::Text *CreateText(sf::Font *font, std::string text, float posX, float posY, unsigned int size, sf::Color color);
};