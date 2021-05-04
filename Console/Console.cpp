#include "Console.h"

Console::Console(sf::Font *font, float gameWidth, float gameHeight, std::function<void(std::string*)> processCommandFunc)
{
	this->font = font;
	this->gameHeight = gameHeight;
	this->gameWidth = gameWidth;
	this->processCommandFunc = processCommandFunc;

	IsActive = false;

	consoleBoxBottom = (gameHeight / 2.f);
	consoleBox = new sf::RectangleShape(sf::Vector2f(gameWidth, consoleBoxBottom));
	consoleBox->setFillColor(sf::Color(0, 0, 255, 200));

	currentLine = new sf::Text();
	currentLine->setString(stringBuffer);
	currentLine->setFillColor(sf::Color::Yellow);
	currentLine->setFont(*font);
	currentLine->setCharacterSize((unsigned int)textSize);
	currentLine->setPosition(5, consoleBoxBottom - textSize - 5);

	Reset();
}

Console::~Console()
{
	delete consoleBox;
	delete currentLine;
	delete font;
}

void Console::Reset()
{
	ResetBuffers();
}

void Console::ResetBuffers()
{
	charBuffer = 0x0;
	stringBuffer = "";
}

void Console::Update()
{
	currentLine->setString(stringBuffer);
}

void Console::Draw(sf::RenderWindow *window)
{
	window->draw(*consoleBox);
	float cmdPosition = 0;

	for (auto cmd: previousCommands)
	{
		window->draw(*TextUtils::CreateText(font, cmd, 0, textSize * cmdPosition++, textSize, sf::Color::Yellow));
	}

	window->draw(*currentLine);
}

void Console::HandleInput(sf::Event *event)
{
	if (event->type == sf::Event::TextEntered)
	{
		sf::Time currentTime = clock.getElapsedTime();

		if (currentTime.asMilliseconds() - lastTimeKeyPressed.asMilliseconds() < 100 &&
			charBuffer == event->text.unicode)
		{
			return;
		}
			

		charBuffer = event->text.unicode;
		stringBuffer += charBuffer;
		
		lastTimeKeyPressed = currentTime;

		if (charBuffer == 13) //Carriage-return
		{
			stringBuffer = stringBuffer.substr(0, stringBuffer.size() - 1); /* Remove the Carriage return */
			
			this->processCommandFunc(&stringBuffer);

			postProcessCommandFunc();
		}

	}
}

void Console::Log(std::string message)
{
	stringBuffer = "DEBUG: " + message;
	postProcessCommandFunc();
}

void Console::postProcessCommandFunc()
{
	if (previousCommands.size() > 8)
	{
		previousCommands.erase(previousCommands.begin(), previousCommands.begin() + 1);
	}

	previousCommands.push_back(stringBuffer);
	stringBuffer = "";
}
