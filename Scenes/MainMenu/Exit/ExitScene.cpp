
#include "ExitScene.h"

ExitScene::ExitScene(sf::Font* font)
{
	this->SetName("MainMenu.Exit");
	txtAreYouSure = TextUtils::CreateText(font, "Are you sure you want to exit ?", 50, 150, 25, sf::Color::Red);

	bufferSfxEat.loadFromFile("eat.ogg");
	bufferSfxEatReverse.loadFromFile("eat_reverse.ogg");
	soundSfxEat.setBuffer(bufferSfxEat);
	soundSfxEatReverse.setBuffer(bufferSfxEatReverse);
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

void ExitScene::HandleInput(sf::Event* event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		soundSfxEatReverse.play();
		SceneManager::GetInstance()->SetCurrentScene("MainMenu");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		soundSfxEat.play();
		sf::sleep(sf::milliseconds(500));
		exit(0);
	}
}
