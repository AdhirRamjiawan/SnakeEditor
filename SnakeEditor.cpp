﻿// SnakeEditor.cpp : Defines the entry point for the application.
//

#include "SnakeEditor.h"
#include "Animations/SpriteAnimator.h"
#include "Animations/GameOver/DyingSnakeAnimator.h"
#include "Scenes/GameOver/GameOverScene.h"
#include "Scenes/Game/GameScene.h"
#include "Scenes/Splash/SplashScene.h"
#include "Scenes/MainMenu/MainMenuScene.h"
#include "Scenes/MainMenu/Credits/CreditsScene.h"
#include "Scenes/MainMenu/Exit/ExitScene.h"
#include "Scenes/Scene.h"
#include "Scenes/SceneManager.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

sf::Font font;


const int gameWidth = 520;
const int gameHeight = 400;
const float snakeMoveWait = 3.f;

int main()
{
    sf::Image iconImage;

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Snake Game!");

    if (iconImage.loadFromFile("icon.bmp"))
    {
        window.setIcon(iconImage.getSize().x, iconImage.getSize().y, iconImage.getPixelsPtr());
    }

    if (!font.loadFromFile("gaming.ttf"))
    {
        cout << "cannot find gaming.ttf" << endl;
        exit(0);
    }
    srand(time(NULL));

    SceneManager *sceneManager = SceneManager::GetInstance();
    sceneManager->AddScene(new SplashScene(&font));
    sceneManager->AddScene(new MainMenuScene(&font));
    sceneManager->AddScene(new CreditsScene(&font));
    sceneManager->AddScene(new ExitScene(&font));
    sceneManager->AddScene(new GameScene(gameWidth, gameHeight));
    sceneManager->AddScene(new GameOverScene(font, gameWidth, gameHeight));

    sceneManager->SetCurrentScene("Splash");

    sf::Clock clock;
    window.setFramerateLimit(10);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sceneManager->GetCurrentScene()->HandleInput();
        sceneManager->GetCurrentScene()->Update();
        sceneManager->GetCurrentScene()->Draw(&window);
    }
	return 0;
}
