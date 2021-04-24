
#include "GameOverScene.h"


GameOverScene::GameOverScene(sf::Font font, float gameWidth, float gameHeight)
{
    this->gameScene = gameScene;
    this->font = font;
    this->gameHeight = gameHeight;
    this->gameWidth = gameWidth;

    this->SetName("GameOver");

    txtGameOver.setFont(this->font);
    txtGameOver.setString("GAME OVER");
    txtGameOver.setCharacterSize(30);
    txtGameOver.setFillColor(sf::Color::Green);
    txtGameOver.setPosition(this->gameWidth / 2, this->gameHeight / 2);
    txtGameOver.setStyle(sf::Text::Regular);

    txtGameOverInstructions.setFont(this->font);
    txtGameOverInstructions.setString("PRESS Q TO QUIT OR ESC TO REPLAY");
    txtGameOverInstructions.setCharacterSize(20);
    txtGameOverInstructions.setFillColor(sf::Color::Red);
    txtGameOverInstructions.setPosition((this->gameWidth / 2) - (txtGameOverInstructions.getGlobalBounds().width / 2), this->gameHeight - 100);
    txtGameOverInstructions.setStyle(sf::Text::Regular);

    dyingSnakeAnimation = new DyingSnakeAnimator();
}

void GameOverScene::Update()
{
    txtGameOver.move(sf::Vector2f(-3.f, 0));

    float rightPositionOfText = txtGameOver.getPosition().x + txtGameOver.getGlobalBounds().width;

    if (rightPositionOfText < 10)
    {
        txtGameOver.setPosition(sf::Vector2f(gameWidth + 10, txtGameOver.getPosition().y));
    }

    dyingSnakeAnimation->UpdateAnimation();
}

void GameOverScene::Draw(sf::RenderWindow* window)
{
    window->setFramerateLimit(60);
    window->clear(sf::Color::Black);

    window->draw(txtGameOver);
    window->draw(txtGameOverInstructions);

    dyingSnakeAnimation->DrawAnimation(window);

    window->display();
}

void GameOverScene::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        SceneManager::GetInstance()->SetCurrentScene("Game");
        SceneManager::GetInstance()->GetCurrentScene()->Reset();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        exit(0);
    }
}

GameOverScene::~GameOverScene()
{
}