// SnakeEditor.cpp : Defines the entry point for the application.
//

#include "SnakeEditor.h"

const float snakeMoveWait = 3.f;

int main()
{
    sf::Image iconImage;
    auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode(GameState::GameWidth, GameState::GameHeight), "Snake Game!");

    if (iconImage.loadFromFile("icon.bmp"))
    {
        window->setIcon(iconImage.getSize().x, iconImage.getSize().y, iconImage.getPixelsPtr());
    }

    srand((unsigned int)time(NULL));
    
    SceneManager *sceneManager = SceneManager::GetInstance();

    sceneManager->SetCurrentScene("Splash");

    window->setFramerateLimit(10);

    // run the program as long as the window is open
    while (window->isOpen())
    {
        window->setKeyRepeatEnabled(false);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();

            sceneManager->GetCurrentScene()->HandleEvent(&event);
        }

        sceneManager->GetCurrentScene()->HandleInput();
        sceneManager->GetCurrentScene()->Update();
        sceneManager->GetCurrentScene()->Draw(window.get());
    }

    delete sceneManager;

	return 0;
}
