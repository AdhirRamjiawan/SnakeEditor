#include "Console.h"

Console::Console(std::shared_ptr<sf::Font> font, std::function<void(std::string*)> processCommandFunc)
{
	this->font = font;
	this->processCommandFunc = processCommandFunc;

	IsActive = false;

	consoleBoxBottom = (GameState::GameHeight / 2.f);
	consoleBox = new sf::RectangleShape(sf::Vector2f(GameState::GameWidth, consoleBoxBottom));
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
}

void Console::Reset()
{
	ResetBuffers();
	previousCommands.clear();
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
#pragma message ("This TextUtils::CreateText method has a memory leak. Gradually allocates memory. Only allocate new Text instances for new strings on the console.")
		window->draw(*TextUtils::CreateText(font, cmd, 0, textSize * cmdPosition++, (unsigned int)textSize, sf::Color::Yellow));
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

		if (charBuffer == 13 /* Carriage-return */)
		{
			stringBuffer = stringBuffer.substr(0, stringBuffer.size() - 1); /* Remove the Carriage return */
			
			this->processCommandFunc(&stringBuffer);

			postProcessCommandFunc();
		}
		else if (charBuffer == 8 /* Backspace */)
		{
			stringBuffer = stringBuffer.substr(0, stringBuffer.size() - 2);
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
