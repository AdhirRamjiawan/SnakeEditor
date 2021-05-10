
#include "LeaderboardScene.h"

LeaderboardScene::LeaderboardScene(sf::Font *font)
{
	this->SetName("Leaderboard");

	float i = 0;
	auto _entries = LeaderboardUtils::Load();

	for (auto entry : _entries)
	{
		entries.push_back(TextUtils::CreateText(font, entry, 100, 120 + (i * 30), 25, sf::Color::White));
	}

	txtTitle = TextUtils::CreateText(font, "Leaderboard", 100, 20, 50, sf::Color::Green);
}

LeaderboardScene::~LeaderboardScene()
{
}

void LeaderboardScene::Update()
{
}

void LeaderboardScene::Draw(sf::RenderWindow* window)
{
	window->setFramerateLimit(60);
	window->clear(sf::Color::Black);

	window->draw(*txtTitle);

	for (auto entry : entries)
	{
		window->draw(*entry);
	}

	window->display();
}

void LeaderboardScene::Reset()
{
}

void LeaderboardScene::HandleEvent(sf::Event* event)
{
}

void LeaderboardScene::HandleInput()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		sf::sleep(sf::milliseconds(5));
		SceneManager::GetInstance()->SetCurrentScene("MainMenu");
	}
}
