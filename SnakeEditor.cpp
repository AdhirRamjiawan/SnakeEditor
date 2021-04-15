// SnakeEditor.cpp : Defines the entry point for the application.
//

#include "SnakeEditor.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

using namespace std;

float snakeLength = 2.0f;
const float snakeBlockSize = 15.f;

const int gameWidth = 520;
const int gameHeight = 400;

int snakeHorizontalDirection = 1;
int snakeVerticalDirection = 1;

float snakeHorizontalSpeed = 0;
float snakeVerticalSpeed = 0;

const float snakeMoveWait = 5.f;
float snakeMoveWaitCount = 0;

bool snakeCollided = false;

bool displayGridEnabled = true;
sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Snake Game!");

sf::RectangleShape snakeHead(sf::Vector2f(snakeBlockSize, snakeBlockSize));
sf::RectangleShape target(sf::Vector2f(snakeBlockSize, snakeBlockSize));

vector<sf::RectangleShape> snakeBlocks;


constexpr int xGridPositionsLength()
{
    return gameWidth / snakeBlockSize;
}

constexpr int yGridPositionsLength()
{
    return gameHeight / snakeBlockSize;
}

vector<int> xGridPositions;
vector<int> yGridPositions;

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
        int randX = rand() % xGridPositionsLength();
        int randY = rand() % yGridPositionsLength();

        cout << "randx " << randX << "randY " << randY << endl;

        int targetX = xGridPositions[randX];
        int targetY = yGridPositions[randY];

        target.setPosition(sf::Vector2f(targetX, targetY));

        cout << "target hit, next target position: x-" << targetX  << ", y-" << targetY << endl;
        snakeLength++;
    }
}

void handleCollision()
{
    if (snakeBlocks.size() <= 2)
        return;

    cout << snakeBlocks.size() << endl;
    for (int i = 0; i < snakeBlocks.size() - 2; i++)
    {
        sf::RectangleShape block = snakeBlocks.at(i);

        if (snakeHead.getPosition().x == block.getPosition().x &&
            snakeHead.getPosition().y == block.getPosition().y)
        {
            cout << "snake ate itself!!!" << endl;
        }
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

void initGame()
{
    srand(time(NULL));

    snakeHead.setFillColor(sf::Color::Green);

    target.setPosition(sf::Vector2f(10 * snakeBlockSize, 10 * snakeBlockSize));
    target.setFillColor(sf::Color::Red);
    
    for (int i = 0; i < gameWidth; i += snakeBlockSize)
        xGridPositions.push_back(i);

    for (int i = 0; i < gameHeight; i += snakeBlockSize)
        yGridPositions.push_back(i);
}

int main()
{
    initGame();

    sf::Clock clock;
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        handleInput();

        float updateDelta = deltaTime.asSeconds();

        if (snakeMoveWaitCount > snakeMoveWait)
        {
            handleTargetHit();
            handleCollision();
            drawGame();
        }
        
        snakeMoveWaitCount += 0.0005f;
    }
	return 0;
}
