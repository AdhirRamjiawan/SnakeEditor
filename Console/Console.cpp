#include "Console.h"

Console::Console(sf::Font *font, float gameWidth, float gameHeight)
{
	consoleBoxBottom = (gameHeight / 2.f);
	consoleBox = new sf::RectangleShape(sf::Vector2f(gameWidth, consoleBoxBottom));
	consoleBox->setFillColor(sf::Color::Blue);

	currentLine = new sf::Text();
	currentLine->setString(">");
	currentLine->setFillColor(sf::Color::Yellow);
	currentLine->setFont(*font);
	currentLine->setCharacterSize(textSize);
	currentLine->setPosition(10, consoleBoxBottom - textSize);
}

Console::~Console()
{
}

void Console::Reset()
{
}

void Console::Update()
{
}

void Console::Draw(sf::RenderWindow *window)
{
	window->draw(*consoleBox);
	
	window->draw(*currentLine);

	//window->display();
}

void Console::HandleInput()
{
	/* ADD SOMETHING TO BASE SCENE CLASS TO DRAW THE COSOLE WINDOW IN THE HANDLEINPUT FUNCTION */
}
