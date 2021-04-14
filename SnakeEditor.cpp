﻿// SnakeEditor.cpp : Defines the entry point for the application.
//

#include "SnakeEditor.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

float snakeSpeed = .025f;
float snakeLength = 2.0f;
float snakeBlockSize = 15.f;

const int gameWidth = 520;
const int gameHeight = 400;

int snakeHorizontalDirection = 1;
int snakeVerticalDirection = 1;

float snakeHorizontalSpeed = 0;
float snakeVerticalSpeed = 0;

const float snakeMoveWait = 10.f;
float snakeMoveWaitCount = 0;

bool snakeCollided = false;

bool displayGridEnabled = true;
sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Snake Game!");

sf::RectangleShape snakeHead(sf::Vector2f(snakeBlockSize, snakeBlockSize));
sf::RectangleShape target(sf::Vector2f(snakeBlockSize, snakeBlockSize));

vector<sf::RectangleShape> snakeBlocks;

void displayGrid()
{
    sf::Color lineColour(100, 100, 100, 255);

    for (int i = 0; i < gameWidth; i += snakeBlockSize)
    {
        sf::RectangleShape line(sf::Vector2f(1, gameHeight));
        line.setPosition(sf::Vector2f(i, 0));
        line.setFillColor(lineColour);
        window.draw(line);
    }

    for (int i = 0; i < gameHeight; i += snakeBlockSize)
    {
        sf::RectangleShape line(sf::Vector2f(gameWidth, 1));
        line.setPosition(sf::Vector2f(0, i));
        line.setFillColor(lineColour);
        window.draw(line);
    }
}

void handleTargetHit()
{
    if (snakeHead.getPosition().x == target.getPosition().x &&
        snakeHead.getPosition().y == target.getPosition().y)
    {
        cout << "target hit" << endl;
        snakeLength++;
    }
}

void handleInput()
{
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // THERE'S A BUG THAT ALLOWS YOU TO COLLIDE THE
    // SNAKE WITH ITSELF. YOU JUST NEED TO PRESS
    // A VERTICAL BUTTON IN QUICK SUCCESSION TO 
    // A HORIZONTAL BUTTON. TO FIX INTRODUCE A 
    // DRAW CALL BOOL OR SOMETHING TO SYNC INPUT
    // WITH DRAW CALLS.
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        displayGridEnabled = !displayGridEnabled;
        cout << "Toggled grid display" << endl;
    }
}

void drawGame()
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

    if (displayGridEnabled)
    {
        displayGrid();
    }

    for (auto block : snakeBlocks)
    {
        window.draw(block);
    }

    window.draw(snakeHead);

    window.draw(target);

    // end the current frame
    window.display();

    snakeMoveWaitCount = 0;

    if (snakeCollided)
    {
        cout << "snake collided!" << endl;
    }
}

int main()
{
    snakeHead.setFillColor(sf::Color::Green);
    sf::Clock clock;
    

    target.setPosition(sf::Vector2f(10 * snakeBlockSize, 10 * snakeBlockSize));
    target.setFillColor(sf::Color::Red);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        handleInput();

        float updateDelta = deltaTime.asSeconds();

        if (snakeMoveWaitCount > snakeMoveWait)
        {
            handleTargetHit();
            drawGame();
        }
        
        snakeMoveWaitCount += 0.0005f;
    }
	return 0;
}
