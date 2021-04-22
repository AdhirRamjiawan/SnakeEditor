
#include "DyingSnakeAnimator.h"


DyingSnakeAnimator::DyingSnakeAnimator()
{
    SpriteAnimator::FrameSpeed = 0.025f;
    this->FrameCount = 0;
    this->FrameIndex = 0;

    SpriteAnimator::SpriteSheet.loadFromFile("snake.png");
    sf::Sprite animationFrame1;
    sf::Sprite animationFrame2;
    sf::Sprite animationFrame3;
    sf::Sprite animationFrame4;
    float posX = 200;
    float posY = 25;

    animationFrame1.setTexture(SpriteAnimator::SpriteSheet);
    animationFrame1.setTextureRect(sf::IntRect(0, 0, 150, 200));
    animationFrame1.setColor(sf::Color(255, 255, 255, 200));
    animationFrame1.setPosition(posX, posY);

    animationFrame2.setTexture(SpriteAnimator::SpriteSheet);
    animationFrame2.setTextureRect(sf::IntRect(152, 0, 150, 200));
    animationFrame2.setColor(sf::Color(255, 255, 255, 200));
    animationFrame2.setPosition(posX, posY);

    animationFrame3.setTexture(SpriteAnimator::SpriteSheet);
    animationFrame3.setTextureRect(sf::IntRect(0, 202, 150, 200));
    animationFrame3.setColor(sf::Color(255, 255, 255, 200));
    animationFrame3.setPosition(posX, posY);

    animationFrame4.setTexture(SpriteAnimator::SpriteSheet);
    animationFrame4.setTextureRect(sf::IntRect(152, 202, 150, 200));
    animationFrame4.setColor(sf::Color(255, 255, 255, 200));
    animationFrame4.setPosition(posX, posY);
    
    SpriteAnimator::Sprites.push_back(animationFrame1);
    SpriteAnimator::Sprites.push_back(animationFrame2);
    SpriteAnimator::Sprites.push_back(animationFrame3);
    SpriteAnimator::Sprites.push_back(animationFrame4);
}

DyingSnakeAnimator::~DyingSnakeAnimator()
{
	SpriteAnimator::~SpriteAnimator();
}