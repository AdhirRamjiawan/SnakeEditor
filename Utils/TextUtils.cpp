
#include "TextUtils.h"

sf::Text *TextUtils::CreateText(std::shared_ptr<sf::Font> font, std::string text, float posX, float posY, unsigned int size, sf::Color color)
{
	sf::Text *txt = new sf::Text();

	txt->setFont(*font.get());
	txt->setString(text);
	txt->setPosition(posX, posY);

	txt->setCharacterSize(size);
	txt->setFillColor(color);
	txt->setStyle(sf::Text::Regular);

	return txt;
};