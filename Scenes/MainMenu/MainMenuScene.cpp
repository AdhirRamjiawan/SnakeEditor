
#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(sf::Font *font)
{
	this->SetName("MainMenu");

	this->sprApple    = SpriteUtils::CreateSprite("apple.png", 100, 100, 100, 50, 0.4f, 0.4f);
	this->txtNewGame  =	TextUtils::CreateText(font, "NEW GAME",  150, 50, 30, sf::Color::White);
	this->txtLoadGame = TextUtils::CreateText(font, "LOAD GAME", 150, 100, 30, sf::Color::White);
	this->txtCredits  =	TextUtils::CreateText(font, "CREDITS",   150, 150, 30, sf::Color::White);
	this->txtOptions  =	TextUtils::CreateText(font, "OPTIONS",   150, 200, 30, sf::Color::White);
	this->txtExit     =	TextUtils::CreateText(font, "EXIT",      150, 250, 30, sf::Color::White);


	bufferSfxEat.loadFromFile("eat.ogg");
	bufferSfxEatReverse.loadFromFile("eat_reverse.ogg");
	soundSfxEat.setBuffer(bufferSfxEat);
	soundSfxEatReverse.setBuffer(bufferSfxEatReverse);
}

MainMenuScene::~MainMenuScene()
{
	delete sprApple;
	delete txtNewGame;
	delete txtLoadGame;
	delete txtCredits;
	delete txtOptions;
	delete txtExit;
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw(sf::RenderWindow* window)
{
	window->setFramerateLimit(10);
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

void MainMenuScene::HandleEvent(sf::Event* event)
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
		soundSfxEat.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (menuPointer == 4)
			return;

		menuPointer++;
		sprApple->move(0, 50);
		soundSfxEat.play();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		soundSfxEat.play();
		if (menuPointer == 0)
		{
			SceneManager::GetInstance()->SetCurrentScene("Game");
			SceneManager::GetInstance()->GetCurrentScene()->Reset();
		}
		else if (menuPointer == 2)
		{
			SceneManager::GetInstance()->SetCurrentScene("MainMenu.Credits");
		}
		else if (menuPointer == 4)
		{
			SceneManager::GetInstance()->SetCurrentScene("MainMenu.Exit");
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
	}
	sf::sleep(sf::milliseconds(5));
}
