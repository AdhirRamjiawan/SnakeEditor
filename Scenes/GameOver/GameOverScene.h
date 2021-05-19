
#pragma once

#include "../Scene.h"
#include "../SceneManager.h"
#include "../../Animations/GameOver/DyingSnakeAnimator.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameOverScene : public Scene 
{
public:
	GameOverScene(std::shared_ptr<sf::Font> font);
	~GameOverScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleEvent(sf::Event* event);
	void HandleInput();
	sf::Text txtGameOver;
	sf::Text txtGameOverInstructions;

private:
	std::shared_ptr<sf::Font> font;
	DyingSnakeAnimator *dyingSnakeAnimation;
};