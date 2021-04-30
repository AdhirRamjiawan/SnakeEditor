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
	void HandleInput(sf::Event* event);
	bool IsActive;

private:
	sf::RectangleShape *consoleBox;
	sf::Text *currentLine;
	float textSize = 20.f;
	float consoleBoxBottom = 0;
	std::string stringBuffer;
	sf::Uint32 charBuffer;
	sf::Clock clock;
	sf::Time lastTimeKeyPressed;
};
