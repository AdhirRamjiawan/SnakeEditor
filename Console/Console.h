#pragma once

#include "../Utils/TextUtils.h"
#include "../State/GameState.h"

#include <SFML/Graphics.hpp>

#include <functional>

class Console
{
public:
	Console(std::shared_ptr<sf::Font> font, std::function<void(std::string*)> processCommandFunc);
	~Console();
	void Reset();
	void ResetBuffers();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput(sf::Event* event);
	void Log(std::string message);
	bool IsActive = false;

private:
	sf::RectangleShape *consoleBox;
	sf::Text *currentLine;
	std::shared_ptr<sf::Font> font;

	float textSize = 20.f;
	float consoleBoxBottom = 0.f;

	std::string stringBuffer = "";
	sf::Uint32 charBuffer = 0;
	sf::Clock clock;
	sf::Time lastTimeKeyPressed;
	std::vector<std::string> previousCommands;

	std::function<void(std::string*)> processCommandFunc;
	void postProcessCommandFunc();
};
