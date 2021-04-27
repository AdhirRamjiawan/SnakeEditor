
#pragma once


#include "../Scene.h"
#include "../SceneManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

class GameScene : public Scene
{
public:
	GameScene(float gameWidth, float gameHeight);
	~GameScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput();
	void Reset();
	bool HasSnakeCollided();
	float GetSnakeMoveWaitCount();
	void IncrementSnakeMoveWaitCount();

private:
	void displayGrid(sf::RenderWindow* window);
	void handleTargetHit();
	void handleCollision();

	float snakeLength = 2.0f;
	int snakeHorizontalDirection = 1;
	int snakeVerticalDirection = 1;

	float snakeHorizontalSpeed = 0;
	float snakeVerticalSpeed = 0;
	float snakeMoveWaitCount = 0;

	bool snakeCollided = false;
	bool displayGridEnabled = true;
	float gameWidth = 0;
	float gameHeight = 0;
	const float snakeBlockSize = 15.f;
	
	std::vector<int> xGridPositions;
	std::vector<int> yGridPositions;
	sf::RectangleShape *snakeHead;
	sf::RectangleShape *target;
	std::vector<sf::RectangleShape> *snakeBlocks;
	sf::Sprite* sprApple;
	const float sprAppleOffset = 5.f;
};
