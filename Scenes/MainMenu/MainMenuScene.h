#pragma once

#include "../Scene.h"
#include "../SceneManager.h"
#include "../Utils/TextUtils.h"
#include "../Utils/SpriteUtils.h"
#include "../Utils/SoundUtils.h"
#include "../State/GameState.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MainMenuScene : public Scene
{
public:
	MainMenuScene(std::shared_ptr<sf::Font> font);
	~MainMenuScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleEvent(sf::Event* event);
	void HandleInput();

private:
	sf::Sprite* sprApple;
	sf::Text *txtNewGame;
	sf::Text *txtLoadGame;
	sf::Text *txtCredits;
	sf::Text *txtOptions;
	sf::Text *txtExit;
	int menuPointer = 0;

	sf::SoundBuffer bufferSfxEat;
	sf::SoundBuffer bufferSfxEatReverse;
	sf::Sound soundSfxEat;
	sf::Sound soundSfxEatReverse;
};
