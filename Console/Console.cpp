#include "Console.h"

Console::Console(sf::Font *font, float gameWidth, float gameHeight)
{
	IsActive = false;

	consoleBoxBottom = (gameHeight / 2.f);
	consoleBox = new sf::RectangleShape(sf::Vector2f(gameWidth, consoleBoxBottom));
	consoleBox->setFillColor(sf::Color(0, 0, 255, 200));

	stringBuffer = ">";

	currentLine = new sf::Text();
	currentLine->setString(stringBuffer);
	currentLine->setFillColor(sf::Color::Yellow);
	currentLine->setFont(*font);
	currentLine->setCharacterSize(textSize);
	currentLine->setPosition(5, consoleBoxBottom - textSize);
}

Console::~Console()
{
}

void Console::Reset()
{
}

void Console::Update()
{
	currentLine->setString(stringBuffer);

	
}

void Console::Draw(sf::RenderWindow *window)
{
	window->draw(*consoleBox);

	window->draw(*currentLine);

	//window->display();
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
	}
}
