
#pragma once


#include "../Scene.h"
#include "../SceneManager.h"
#include "../State/GameState.h"
#include "../Console/Console.h"
#include "../Utils/SoundUtils.h"
#include "../Utils/LevelUtils.h"
#include "../State/Level.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <functional>
#include <vector>

class GameScene : public Scene
{
public:
	GameScene(std::shared_ptr<sf::Font> font);
	~GameScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleEvent(sf::Event* event);
	void HandleInput();
	void Reset();

private:
	void displayGrid(sf::RenderWindow* window);
	void handleTargetHit();
	void handleCollision();
	static void processCommand(std::string* command);
	void loadLevel(int levelIndex);
	
	float snakeLength = 2.0f;
	int snakeHorizontalDirection = 1;
	int snakeVerticalDirection = 1;

	float snakeHorizontalSpeed = 0;
	float snakeVerticalSpeed = 0;
	float snakeMoveWaitCount = 0;

	bool gamePaused = false;
	bool snakeCollided = false;
	float gameWidth = 0;
	float gameHeight = 0;
	
	std::vector<int> xGridPositions;
	std::vector<int> yGridPositions;
	sf::RectangleShape *snakeHead;
	std::vector<sf::RectangleShape> *snakeBlocks;
	sf::Sprite* sprApple;
	
	const float snakeBlockSize = 15.f;
	const float sprAppleOffset = 5.f;


	sf::SoundBuffer bufferMusic;
	sf::SoundBuffer bufferSfxEat;
	sf::Sound soundMusic;
	sf::Sound soundSfxEat;
	float soundMusicVolume = 50.f;

	GameState* gameState;
	sf::Text* txtScore;

	struct LevelModel currentLevel;
	sf::Text* txtLevelName;
	sf::Text* txtLevelComplete;
	int currentLevelIndex = 1;
	float levelLoadDelayThreshold = 5.0f;

	sf::Clock clock;
	sf::Time clockElapsed;

	sf::Text* txtQuitGame;
	bool quitGamePromptEnabled = false;
};
