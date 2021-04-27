
#include "CreditsScene.h"


CreditsScene::CreditsScene(sf::Font *font)
{
    this->SetName("MainMenu.Credits");

    txtCreatedBy        = TextUtils::CreateText(font, "CREATED BY", 50, 50, 25, sf::Color::White);
    txtCreatedByValue   = TextUtils::CreateText(font, "ADHIR RAMJIAWAN", 50, 100, 25, sf::Color::White);
    txtCreatedYear      = TextUtils::CreateText(font, "2021", 50, 150, 25, sf::Color::White);
    txtEmail            = TextUtils::CreateText(font, "ADHIRRAMJIAWAN0@GMAIL.COM", 50, 200, 25, sf::Color::White);
}

void CreditsScene::Update()
{
}

void CreditsScene::Draw(sf::RenderWindow* window)
{
    window->clear(sf::Color::Black);

    window->draw(*txtCreatedBy);
    window->draw(*txtCreatedByValue);
    window->draw(*txtCreatedYear);
    window->draw(*txtEmail);

    window->display();
}

void CreditsScene::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        SceneManager::GetInstance()->SetCurrentScene("MainMenu");
    }
}

CreditsScene::~CreditsScene()
{
}