#include "SpriteUtils.h"

sf::Sprite *SpriteUtils::CreateSprite(std::string textureFile, int width, int height, float posX, float posY, float scaleX, float scaleY)
{
	sf::Sprite *sprite = new sf::Sprite();
	sf::Texture* spriteSheet = new sf::Texture();

	spriteSheet->loadFromFile(textureFile);
	
	sprite->setTexture(*spriteSheet);
	sprite->setTextureRect(sf::IntRect(0, 0, width, height));
	sprite->setColor(sf::Color(255, 255, 255, 200));
	sprite->setPosition(posX, posY);
	sprite->setScale(scaleX, scaleY);

	return sprite;
}