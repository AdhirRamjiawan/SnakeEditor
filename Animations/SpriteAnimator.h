
#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SpriteAnimator
{
public:
	SpriteAnimator();
	~SpriteAnimator();
	std::vector<sf::Sprite> Sprites;
	sf::Texture SpriteSheet;
	void UpdateAnimation();
	void DrawAnimation(sf::RenderWindow *window);

protected:
	float FrameCount = 0.f;
	int FrameIndex = 0;
	float FrameSpeed = 0.f;
};