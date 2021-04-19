// SnakeEditor.cpp : Defines the entry point for the application.
//

#include "SnakeEditor.h"
#include "Animations/SpriteAnimator.h"
#include "Animations/GameOver/DyingSnakeAnimator.h"
#include "Scenes/GameOver/GameOverScene.h"
#include "Scenes/Game/GameScene.h"

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
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Snake Game!");

    if (!font.loadFromFile("gaming.ttf"))
    {
        cout << "cannot find gaming.ttf" << endl;
        exit(0);
    }
    srand(time(NULL));

    GameScene gameScene(gameWidth, gameHeight);
    GameOverScene gameOverScene(&gameScene, font, gameWidth, gameHeight);

    sf::Clock clock;
    
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

        if (gameScene.HasSnakeCollided())
        {
            gameOverScene.HandleInput();
            gameOverScene.Update();
            gameOverScene.Draw(&window);
            continue;
        }

        gameScene.HandleInput();

        // TODO: change this to use a proper game loop that operates on FPS
        if (gameScene.GetSnakeMoveWaitCount() > snakeMoveWait)
        {
            gameScene.Update();
            gameScene.Draw(&window);
        }
        
        gameScene.IncrementSnakeMoveWaitCount();
    }
	return 0;
}
