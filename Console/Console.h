#pragma once

#include <SFML/Graphics.hpp>

class Console
{
public:
	Console(sf::Font* font, float gameWidth, float gameHeight);
	~Console();
	void Reset();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput();

private:
	sf::RectangleShape *consoleBox;
	sf::Text *currentLine;
	float textSize = 10.f;
	float consoleBoxBottom = 0;
};
