
#include "GameScene.h"
#include "../../Utils/SpriteUtils.h"

GameScene::GameScene(std::shared_ptr<sf::Font> font)
{
    this->SetName("Game");
    this->gameState = new GameState();
    currentLevel = LevelUtils::GetLevel("level1.dat");

    txtScore = TextUtils::CreateText(font, "Score: 0", 10.f, 10.f, 20, sf::Color::White);
    snakeHead = new sf::RectangleShape(sf::Vector2f(snakeBlockSize, snakeBlockSize));
    txtLevelName = TextUtils::CreateText(font, currentLevel.Name, 300.f, 10.f, 20, sf::Color::Red);
    txtLevelComplete = TextUtils::CreateText(font, "Level Complete!", 50.f, 200.f, 50, sf::Color::Green);
    txtQuitGame = TextUtils::CreateText(font, "Are you sure on quiting?", 70.f, 150.f, 30, sf::Color::Red);

    snakeBlocks = new std::vector<sf::RectangleShape>();
    sprApples = new std::vector<sf::Sprite*>();

    auto initialApple = this->createAppleSprite(10, 10);
    sprApples->push_back(initialApple);

    this->snakeHead->setFillColor(sf::Color::Green);

    for (int i = 0; i < GameState::GameWidth; i += int(snakeBlockSize))
        xGridPositions.push_back(i);

    for (int i = 0; i < GameState::GameHeight; i += int(snakeBlockSize))
        yGridPositions.push_back(i);

    bufferMusic.loadFromFile("game_scene.ogg");
    bufferSfxEat.loadFromFile("eat.ogg");
    soundMusic.setBuffer(bufferMusic);
    soundSfxEat.setBuffer(bufferSfxEat);

    DevConsole = new Console(font, processCommand);
    this->snakeHead->setPosition(sf::Vector2f(currentLevel.Player.PositionX, currentLevel.Player.PositionY));

    clock = sf::Clock();
}

GameScene::~GameScene()
{
    delete snakeHead;
    delete snakeBlocks;
    delete sprApples;
    delete gameState;
}

void GameScene::Reset()
{
    this->snakeHead->setPosition(sf::Vector2f(currentLevel.Player.PositionX, currentLevel.Player.PositionY));
    this->snakeBlocks->clear();

    snakeLength = 2.0f;
    snakeHorizontalDirection = 1;
    snakeVerticalDirection = 1;

    snakeHorizontalSpeed = 0;
    snakeVerticalSpeed = 0;
    snakeMoveWaitCount = 0;

    snakeCollided = false;
    quitGamePromptEnabled = false;

    gameState->Reset();
    DevConsole->Reset();

    txtScore->setString("Score: " + std::to_string(gameState->PlayerScore));
    clock.restart();
}

void GameScene::Update()
{
    if (DevConsole->IsActive)
    {
        DevConsole->Update();
    }

    if (gamePaused || gameState->LevelComplete)
        return;

    if (this->soundMusic.getStatus() != sf::SoundSource::Status::Playing)
    {
        this->soundMusic.setVolume(soundMusicVolume);
        this->soundMusic.setLoop(true);
        SoundUtils::PlayMusic(&soundMusic);
    }

    if (this->snakeCollided)
    {
        SoundUtils::StopMusic(&soundMusic);
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
    {
        DevConsole->IsActive = !DevConsole->IsActive;
        gamePaused = DevConsole->IsActive;
        sf::sleep(sf::milliseconds(100));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        if (quitGamePromptEnabled)
        {
            quitGamePromptEnabled = false;
            sf::sleep(sf::milliseconds(250));
        }
        else
        {
            quitGamePromptEnabled = true;
            sf::sleep(sf::milliseconds(250));
        }   

        gamePaused = quitGamePromptEnabled;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (quitGamePromptEnabled)
        {
            SceneManager::GetInstance()->SetCurrentScene("MainMenu");
        }
    }

}

void GameScene::Draw(sf::RenderWindow *window)
{
    window->setFramerateLimit(10);
    window->clear(sf::Color::Black);

    if (GameState::Config.DisplayGrid)
    {
        displayGrid(window);
    }

    for (auto block : *this->snakeBlocks)
    {
        window->draw(block);
    }

    window->draw(*snakeHead);
    window->draw(*txtScore);
    window->draw(*txtLevelName);

    for (auto apple : *this->sprApples)
    {
        window->draw(*apple);
    }

    if (quitGamePromptEnabled)
    {
        window->draw(*txtQuitGame);
    }

    if (gameState->LevelComplete)
    {
        clock.restart();
        clockElapsed = clock.getElapsedTime();

        while (true)
        {
            auto delta = (clock.getElapsedTime() - clockElapsed).asSeconds();

            if (delta > levelLoadDelayThreshold)
            {
                loadLevel(++currentLevelIndex);
                break;
            }

            window->draw(*this->txtLevelComplete);
            window->display();
        }
    }

    if (DevConsole->IsActive)
    {
        DevConsole->Draw(window);
    }

    window->display();
}

void GameScene::HandleEvent(sf::Event* event)
{
    if (DevConsole->IsActive)
    {
        DevConsole->HandleInput(event);
    }
    else
    {
        DevConsole->ResetBuffers();
    }
}


void GameScene::displayGrid(sf::RenderWindow* window)
{
    sf::Color lineColour(100, 100, 100, 255);

    for (int i = 0; i < GameState::GameWidth; i += int(this->snakeBlockSize))
    {
        sf::RectangleShape line(sf::Vector2f(1, GameState::GameHeight));
        line.setPosition(float(i), float(0));
        line.setFillColor(lineColour);
        window->draw(line);
    }

    for (int i = 0; i < GameState::GameHeight; i += int(snakeBlockSize))
    {
        sf::RectangleShape line(sf::Vector2f(GameState::GameWidth, 1));
        line.setPosition(sf::Vector2f(0, float(i)));
        line.setFillColor(lineColour);
        window->draw(line);
    }
}

void GameScene::handleTargetHit()
{

    for (auto apple : *this->sprApples)
    {
        checkSingleAppleTargetHit(apple);
    }
}

void GameScene::checkSingleAppleTargetHit(sf::Sprite *sprApple)
{
    if (this->snakeHead->getPosition().x == (sprApple->getPosition().x + sprAppleOffset) &&
        this->snakeHead->getPosition().y == (sprApple->getPosition().y + sprAppleOffset))
    {
        handleSingleAppleTargetHit(sprApple);
    }
}

void GameScene::handleSingleAppleTargetHit(sf::Sprite *sprApple)
{
    int targetX = this->getRandX();
    int targetY = this->getRandY();

    sprApple->setPosition(sf::Vector2f(targetX - sprAppleOffset, targetY - sprAppleOffset));

    //cout << "target hit, next target position: x-" << targetX << ", y-" << targetY << endl;
    snakeLength++;

    SoundUtils::PlaySfx(&soundSfxEat);

    this->DevConsole->Log("Target hit!");

    gameState->PlayerScore += 1;
    txtScore->setString("Score: " + std::to_string(gameState->PlayerScore));

    if (gameState->PlayerScore >= currentLevel.WinCount)
    {
        gameState->LevelComplete = true;
    }
}

int GameScene::getRandX()
{
    int xGridPositionsLength = int(GameState::GameWidth / this->snakeBlockSize);
    int randX = rand() % xGridPositionsLength;

    return xGridPositions[randX];
}

int GameScene::getRandY()
{
    int yGridPositionsLength = int(GameState::GameHeight / this->snakeBlockSize);
    int randY = rand() % yGridPositionsLength;

    return yGridPositions[randY];
}

void GameScene::handleCollision()
{
    /* Check collision with borders */
    if (this->snakeHead->getPosition().x < 0 || this->snakeHead->getPosition().x > GameState::GameWidth ||
        this->snakeHead->getPosition().y < 0 || this->snakeHead->getPosition().y > GameState::GameHeight)
    {
        //cout << "snake bumped its head!!!" << endl;
        snakeCollided = !GameState::Config.GodMode;
        return;
    }

    /* vv Check collision with itself vv */
    if (this->snakeBlocks->size() <= 2 || GameState::Config.GodMode)
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

void GameScene::processCommand(std::string* command)
{
    GameScene *scene = (GameScene*)SceneManager::GetInstance()->GetCurrentScene();

    if (*command == "exit")
    {
        exit(0);
    }
    else if (*command == "cls")
    {
        scene->DevConsole->Reset();
    }
    else if (*command == "grid")
    {
        GameState::Config.DisplayGrid = !GameState::Config.DisplayGrid;
    }
    else if (*command == "reset")
    {
        scene->Reset();
    }
    else if (*command == "god")
    {
        GameState::Config.GodMode = !GameState::Config.GodMode;
        scene->DevConsole->Log("God mode: " + GameState::Config.GodMode);
    }
    else if (*command == "stat")
    {
        scene->displayStat(scene);
    }
    else if (command->find("spawn") == 0)
    {
        scene->handleSpawn(command);
    }
    else if (*command == "banish")
    {
        scene->handleBanish();
    }
    else
    {
        //stringBuffer = "unknown command '" + stringBuffer + "'";
    }
}

void GameScene::handleBanish()
{
    this->sprApples->clear();
}

void GameScene::handleSpawn(std::string *command)
{
    auto trimmedString = StringUtils::Trim(*command);
    auto spawnCommandParts = StringUtils::Split(trimmedString, " ");

    if (spawnCommandParts.size() < 4)
    {
        if (spawnCommandParts.size() == 2)
        {
            this->handleRandomSpawn();
            return;
        }

        this->DevConsole->Log("usage: spawn [object] [posx] [posy]");
        return;
    }

    auto object = spawnCommandParts.at(1);
    auto xPos = atoi(spawnCommandParts.at(2).c_str());
    auto yPos = atoi(spawnCommandParts.at(3).c_str());

    this->spawnApple(xPos, yPos);
}

void GameScene::handleRandomSpawn()
{
    auto xPos = this->getRandX();
    auto yPos = this->getRandY();

    this->spawnApple(xPos / this->snakeBlockSize, yPos / this->snakeBlockSize);
}

void GameScene::spawnApple(int x, int y)
{
    auto apple = this->createAppleSprite(x, y);
    this->sprApples->push_back(apple);
}

void GameScene::displayStat(GameScene *scene)
{
    std::string statResult = "";

    if (GameState::Config.GodMode)
    {
        statResult = statResult + "God" + "|";
    }

    if (GameState::Config.DisplayGrid)
    {
        statResult = statResult + "Grid" + "|";
    }

    if (GameState::Config.PlayMusic)
    {
        statResult = statResult + "Music" + "|";
    }

    if (GameState::Config.PlaySfx)
    {
        statResult = statResult + "Sfx" + "|";
    }

    scene->DevConsole->Log(statResult);
}

void GameScene::loadLevel(int levelIndex)
{
    currentLevel = LevelUtils::GetLevel("level" + std::to_string(levelIndex) + ".dat");
    txtLevelName->setString(currentLevel.Name);
    Reset();
}

sf::Sprite *GameScene::createAppleSprite(int x, int y)
{
    auto finalXPos = (x * snakeBlockSize) - sprAppleOffset;
    auto finalYPos = (y * snakeBlockSize) - sprAppleOffset;

    return SpriteUtils::CreateSprite("apple.png", 100, 100, finalXPos, finalYPos, snakeBlockSize / 60, snakeBlockSize / 60);
}