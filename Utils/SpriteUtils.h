#pragma once

#include <SFML/Graphics.hpp>

class SpriteUtils
{
public:
	static sf::Sprite *CreateSprite(std::string textureFile, int width, int height, float posX, float posY, float scaleX, float scaleY);
};
