
#include "ExitScene.h"

ExitScene::ExitScene(sf::Font* font)
{
	this->SetName("MainMenu.Exit");
	txtAreYouSure = TextUtils::CreateText(font, "ARE YOU SURE YOU WANT TO EXIT?", 30, 100, 20, sf::Color::Red);
}

ExitScene::~ExitScene()
{
}

void ExitScene::Update()
{
}

void ExitScene::Draw(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);

	window->draw(*txtAreYouSure);

	window->display();
}

void ExitScene::Reset()
{
}

void ExitScene::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		SceneManager::GetInstance()->SetCurrentScene("MainMenu");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		exit(0);
	}
}
