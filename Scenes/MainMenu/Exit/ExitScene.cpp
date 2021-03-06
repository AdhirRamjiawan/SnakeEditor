
#include "ExitScene.h"

ExitScene::ExitScene(std::shared_ptr<sf::Font> font)
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
	delete txtAreYouSure;
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

void ExitScene::HandleEvent(sf::Event* event)
{
}

void ExitScene::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		SoundUtils::PlaySfx(&soundSfxEatReverse);
		SceneManager::GetInstance()->SetCurrentScene("MainMenu");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		SoundUtils::PlaySfx(&soundSfxEat);
		sf::sleep(sf::milliseconds(500));
		exit(0);
	}
}
