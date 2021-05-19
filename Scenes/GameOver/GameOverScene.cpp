
#include "GameOverScene.h"


GameOverScene::GameOverScene(std::shared_ptr<sf::Font> font)
{
    this->font = font;

    this->SetName("GameOver");

    txtGameOver.setFont(*this->font);
    txtGameOver.setString("GAME OVER");
    txtGameOver.setCharacterSize(30);
    txtGameOver.setFillColor(sf::Color::Green);
    txtGameOver.setPosition(GameState::GameWidth / 2, GameState::GameHeight / 2);
    txtGameOver.setStyle(sf::Text::Regular);

    txtGameOverInstructions.setFont(*this->font);
    txtGameOverInstructions.setString("Press Escape to go to the main menu");
    txtGameOverInstructions.setCharacterSize(20);
    txtGameOverInstructions.setFillColor(sf::Color::Red);
    txtGameOverInstructions.setPosition((GameState::GameWidth / 2) - (txtGameOverInstructions.getGlobalBounds().width / 2), GameState::GameHeight - 100);
    txtGameOverInstructions.setStyle(sf::Text::Regular);

    dyingSnakeAnimation = new DyingSnakeAnimator();


}

void GameOverScene::Update()
{
    txtGameOver.move(sf::Vector2f(-3.f, 0));

    float rightPositionOfText = txtGameOver.getPosition().x + txtGameOver.getGlobalBounds().width;

    if (rightPositionOfText < 10)
    {
        txtGameOver.setPosition(sf::Vector2f(GameState::GameWidth + 10, txtGameOver.getPosition().y));
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

void GameOverScene::HandleEvent(sf::Event* event)
{
}

void GameOverScene::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        SceneManager::GetInstance()->SetCurrentScene("Leaderboard");
    }
}

GameOverScene::~GameOverScene()
{
    delete dyingSnakeAnimation;
}