// SnakeEditor.cpp : Defines the entry point for the application.
//

#include "SnakeEditor.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

float snakeSpeed = .025f;
float snakeLength = 12.0f;
float snakeBlockSize = 15.f;

const int gameWidth = 520;
const int gameHeight = 400;

int main()
{
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Snake Game!");
    sf::Clock clock;
    sf::RectangleShape snakeHead(sf::Vector2f(snakeBlockSize, snakeBlockSize));
    snakeHead.setFillColor(sf::Color::Green);
    vector<sf::RectangleShape> snakeBlocks;

    int snakeHorizontalDirection = 1;
    int snakeVerticalDirection = 1;
    
    float snakeHorizontalSpeed = 0;
    float snakeVerticalSpeed = 0;

    const float snakeMoveWait = 10.f;
    float snakeMoveWaitCount = 0;

    bool snakeCollided = false;

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (snakeHorizontalSpeed == 0)
            {
                snakeHorizontalDirection = -1;
                snakeHorizontalSpeed = snakeBlockSize;
                snakeVerticalSpeed = 0;
            }
            
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (snakeHorizontalSpeed == 0)
            {
                snakeHorizontalDirection = 1;
                snakeHorizontalSpeed = snakeBlockSize;
                snakeVerticalSpeed = 0;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (snakeVerticalSpeed == 0)
            {
                snakeVerticalDirection = -1;
                snakeHorizontalSpeed = 0;
                snakeVerticalSpeed = snakeBlockSize;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (snakeVerticalSpeed == 0)
            {
                snakeVerticalDirection = 1;
                snakeHorizontalSpeed = 0;
                snakeVerticalSpeed = snakeBlockSize;
            }
        }

        float updateDelta = deltaTime.asSeconds();

        if (snakeMoveWaitCount > snakeMoveWait)
        {
            window.clear(sf::Color::Black);

            snakeHead.setPosition(sf::Vector2f(
                snakeHead.getPosition().x + snakeHorizontalSpeed * snakeHorizontalDirection,
                snakeHead.getPosition().y + snakeVerticalSpeed * snakeVerticalDirection
            ));

            sf::RectangleShape lastBlock(sf::Vector2f(snakeBlockSize, snakeBlockSize));
            lastBlock.setPosition(sf::Vector2f(
                snakeHead.getPosition().x,
                snakeHead.getPosition().y
            ));

            snakeBlocks.push_back(lastBlock);

            if (snakeBlocks.size() > snakeLength)
            {
                snakeBlocks.erase(snakeBlocks.begin(), snakeBlocks.begin() + 1);
            }

            for (auto block : snakeBlocks)
            {
                window.draw(block);
            }

            window.draw(snakeHead);

            // end the current frame
            window.display();

            snakeMoveWaitCount = 0;

            if (snakeCollided)
            {
                cout << "snake collided!" << endl;
            }
        }
        
        snakeMoveWaitCount += 0.0005f;
    }
	return 0;
}
