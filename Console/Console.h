#pragma once

#include "../Utils/TextUtils.h"
#include <SFML/Graphics.hpp>

#include <functional>

class Console
{
public:
	Console(sf::Font* font, float gameWidth, float gameHeight, std::function<void(std::string*)> processCommandFunc);
	~Console();
	void Reset();
	void ResetBuffers();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput(sf::Event* event);
	void Log(std::string message);
	bool IsActive;

private:
	sf::RectangleShape *consoleBox;
	sf::Text *currentLine;
	sf::Font* font;

	float textSize = 20.f;
	float consoleBoxBottom = 0;
	float gameHeight;
	float gameWidth;

	std::string stringBuffer;
	sf::Uint32 charBuffer;
	sf::Clock clock;
	sf::Time lastTimeKeyPressed;
	std::vector<std::string> previousCommands;

	std::function<void(std::string*)> processCommandFunc;
	void postProcessCommandFunc();
};
