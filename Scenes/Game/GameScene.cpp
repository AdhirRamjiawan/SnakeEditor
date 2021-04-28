
#include "GameScene.h"
#include "../../Utils/SpriteUtils.h"

GameScene::GameScene(float gameWidth, float gameHeight)
{
    this->SetName("Game");
    this->gameWidth = gameWidth;
    this->gameHeight = gameHeight;

    this->sprApple = SpriteUtils::CreateSprite("apple.png", 100, 100, (10 * snakeBlockSize) - sprAppleOffset, (10 * snakeBlockSize) - sprAppleOffset, snakeBlockSize / 60, snakeBlockSize / 60);
    this->snakeHead = new sf::RectangleShape(sf::Vector2f(snakeBlockSize, snakeBlockSize));

    snakeBlocks = new std::vector<sf::RectangleShape>();

    this->snakeHead->setFillColor(sf::Color::Green);

    for (int i = 0; i < this->gameWidth; i += snakeBlockSize)
        xGridPositions.push_back(i);

    for (int i = 0; i < this->gameHeight; i += snakeBlockSize)
        yGridPositions.push_back(i);
}

GameScene::~GameScene()
{
	Scene::~Scene();
}

void GameScene::Reset()
{
    this->snakeHead->setPosition(sf::Vector2f(snakeBlockSize, snakeBlockSize));
    this->snakeBlocks->clear();

    snakeLength = 2.0f;
    snakeHorizontalDirection = 1;
    snakeVerticalDirection = 1;

    snakeHorizontalSpeed = 0;
    snakeVerticalSpeed = 0;
    snakeMoveWaitCount = 0;

    displayGridEnabled = true;

    snakeCollided = false;
}

void GameScene::Update()
{
    if (this->snakeCollided)
    {
        SceneManager::GetInstance()->SetCurrentScene("GameOver");
        return;
    }

    this->handleTargetHit();
    this->handleCollision();

    this->snakeHead->setPosition(sf::Vector2f(
        this->snakeHead->getPosition().x + snakeHorizontalSpeed * snakeHorizontalDirection,
        this->snakeHead->getPosition().y + snakeVerticalSpeed * snakeVerticalDirection
    ));

    sf::RectangleShape lastBlock(sf::Vector2f(snakeBlockSize, snakeBlockSize));
    lastBlock.setPosition(sf::Vector2f(
        this->snakeHead->getPosition().x,
        this->snakeHead->getPosition().y
    ));

    this->snakeBlocks->push_back(lastBlock);

    if (this->snakeBlocks->size() > snakeLength)
    {
        this->snakeBlocks->erase(this->snakeBlocks->begin(), this->snakeBlocks->begin() + 1);
    }
}

void GameScene::HandleInput()
{
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
        //cout << "Toggled grid display" << endl;
    }
}

void GameScene::Draw(sf::RenderWindow *window)
{
    window->setFramerateLimit(10);
    window->clear(sf::Color::Black);

    if (displayGridEnabled)
    {
        displayGrid(window);
    }

    for (auto block : *this->snakeBlocks)
    {
        window->draw(block);
    }

    window->draw(*this->snakeHead);
    window->draw(*this->sprApple);

    window->display();
}


void GameScene::displayGrid(sf::RenderWindow* window)
{
    sf::Color lineColour(100, 100, 100, 255);

    for (int i = 0; i < this->gameWidth; i += this->snakeBlockSize)
    {
        sf::RectangleShape line(sf::Vector2f(1, gameHeight));
        line.setPosition(sf::Vector2f(i, 0));
        line.setFillColor(lineColour);
        window->draw(line);
    }

    for (int i = 0; i < gameHeight; i += snakeBlockSize)
    {
        sf::RectangleShape line(sf::Vector2f(gameWidth, 1));
        line.setPosition(sf::Vector2f(0, i));
        line.setFillColor(lineColour);
        window->draw(line);
    }
}

void GameScene::handleTargetHit()
{
    int xGridPositionsLength = this->gameWidth / this->snakeBlockSize;
    int yGridPositionsLength = this->gameHeight / this->snakeBlockSize;

    if (this->snakeHead->getPosition().x == (this->sprApple->getPosition().x + sprAppleOffset) &&
        this->snakeHead->getPosition().y == (this->sprApple->getPosition().y + sprAppleOffset))
    {
        int randX = rand() % xGridPositionsLength;
        int randY = rand() % yGridPositionsLength;

        //cout << "randx " << randX << "randY " << randY << endl;

        int targetX = xGridPositions[randX];
        int targetY = yGridPositions[randY];

        this->sprApple->setPosition(sf::Vector2f(targetX - sprAppleOffset, targetY - sprAppleOffset));

        //cout << "target hit, next target position: x-" << targetX << ", y-" << targetY << endl;
        snakeLength++;
    }
}

void GameScene::handleCollision()
{
    /* Check collision with borders */
    if (this->snakeHead->getPosition().x < 0 || this->snakeHead->getPosition().x > gameWidth ||
        this->snakeHead->getPosition().y < 0 || this->snakeHead->getPosition().y > gameHeight)
    {
        //cout << "snake bumped its head!!!" << endl;
        snakeCollided = true;
        return;
    }

    /* vv Check collision with itself vv */
    if (this->snakeBlocks->size() <= 2)
        return;

    for (int i = 0; i < this->snakeBlocks->size() - 2; i++)
    {
        sf::RectangleShape block = this->snakeBlocks->at(i);

        if (this->snakeHead->getPosition().x == block.getPosition().x &&
            this->snakeHead->getPosition().y == block.getPosition().y)
        {
            //cout << "snake ate itself!!!" << endl;
            snakeCollided = true;
            break;
        }
    }
}