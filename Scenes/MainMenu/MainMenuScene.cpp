
#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(sf::Font *font)
{
	this->SetName("MainMenu");

	this->sprApple = SpriteUtils::CreateSprite("apple.png", 100, 100, 100, 50, 0.4, 0.4);
	this->txtNewGame =	TextUtils::CreateText(font, "NEW GAME",		150, 50, 30, sf::Color::White);
	this->txtLoadGame = TextUtils::CreateText(font, "LOAD GAME",	150, 100, 30, sf::Color::White);
	this->txtCredits =	TextUtils::CreateText(font, "CREDITS",		150, 150, 30, sf::Color::White);
	this->txtOptions =	TextUtils::CreateText(font, "OPTIONS",		150, 200, 30, sf::Color::White);
	this->txtExit =		TextUtils::CreateText(font, "EXIT",			150, 250, 30, sf::Color::White);
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);

	window->draw(*sprApple);
	window->draw(*txtNewGame);
	window->draw(*txtLoadGame);
	window->draw(*txtCredits);
	window->draw(*txtOptions);
	window->draw(*txtExit);

	window->display();
}

void MainMenuScene::Reset()
{
}

void MainMenuScene::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (menuPointer == 0)
			return;

		menuPointer--;
		sprApple->move(0, -50);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (menuPointer == 4)
			return;

		menuPointer++;
		sprApple->move(0, 50);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (menuPointer == 0)
		{
			SceneManager::GetInstance()->SetCurrentScene("Game");
		}
		else if (menuPointer == 2)
		{
			SceneManager::GetInstance()->SetCurrentScene("MainMenu.Credits");
		}
		else if (menuPointer == 4)
		{
			exit(0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		
	}
}
