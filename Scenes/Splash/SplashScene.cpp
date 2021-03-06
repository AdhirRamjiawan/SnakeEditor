
#include "SplashScene.h"


SplashScene::SplashScene(std::shared_ptr<sf::Font> font)
{
	this->SetName("Splash");
	this->spriteSheet.loadFromFile("snake.png");

	snakeSprite.setTexture(this->spriteSheet);
	snakeSprite.setTextureRect(sf::IntRect(0, 0, 150, 200));
	snakeSprite.setColor(sf::Color(255, 255, 255, 200));
	snakeSprite.setPosition(10, 30);
	snakeSprite.setScale(2.f, 2.f);

	txtTitle = TextUtils::CreateText(font, "SNAKE", 310.f, 50.f, 40, sf::Color::Red);
	txtCreatedBy = TextUtils::CreateText(font, "Created by Adhir Ramjiawan  2021", 100, 350, 20, sf::Color::Blue);
	txtContinue = TextUtils::CreateText(font, "PRESS ENTER TO CONTINUE", 270, 150, 15, sf::Color::Green);
}

SplashScene::~SplashScene()
{
	delete txtTitle;
	delete txtCreatedBy;
	delete txtContinue;
}

void SplashScene::Update()
{
}

void SplashScene::Draw(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);
	window->draw(snakeSprite);

	window->draw(*txtTitle); 
	window->draw(*txtCreatedBy); 
	window->draw(*txtContinue); 
	
	window->display();
}

void SplashScene::Reset()
{
}

void SplashScene::HandleEvent(sf::Event* event)
{
}

void SplashScene::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		SceneManager::GetInstance()->SetCurrentScene("MainMenu");
	}
}
