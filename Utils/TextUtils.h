#pragma once

#include <SFML/Graphics.hpp>

class TextUtils
{
public:
	static sf::Text *CreateText(sf::Font *font, std::string text, float posX, float posY, float size, sf::Color color);
};