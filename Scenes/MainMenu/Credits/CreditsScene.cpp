
#include "CreditsScene.h"


CreditsScene::CreditsScene(sf::Font *font)
{
    this->SetName("MainMenu.Credits");

    txtCreatedBy        = TextUtils::CreateText(font, "Created by", 50, 50, 25, sf::Color::White);
    txtCreatedByValue   = TextUtils::CreateText(font, "Adhir Ramjiawan", 50, 100, 25, sf::Color::White);
    txtCreatedYear      = TextUtils::CreateText(font, "2021", 50, 150, 25, sf::Color::White);
    txtEmail            = TextUtils::CreateText(font, "adhirramjiawan0@gmail.com", 50, 200, 25, sf::Color::White);

    bufferSfxEatReverse.loadFromFile("eat_reverse.ogg");
    soundSfxEatReverse.setBuffer(bufferSfxEatReverse);
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

void CreditsScene::HandleEvent(sf::Event* event)
{
}

void CreditsScene::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        soundSfxEatReverse.play();
        SceneManager::GetInstance()->SetCurrentScene("MainMenu");
    }
}

CreditsScene::~CreditsScene()
{
    delete txtCreatedBy;
    delete txtCreatedByValue;
    delete txtCreatedYear;
    delete txtEmail;
}