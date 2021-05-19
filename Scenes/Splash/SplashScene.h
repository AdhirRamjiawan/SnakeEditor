
#pragma once

#include "../Scene.h"
#include "../SceneManager.h"
#include "../Utils/TextUtils.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SplashScene : public Scene
{
public:
	SplashScene(std::shared_ptr<sf::Font> font);
	~SplashScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleEvent(sf::Event* event);
	void HandleInput();

private:
	sf::Texture spriteSheet;
	sf::Sprite snakeSprite;
	sf::Text *txtTitle;
	sf::Text* txtCreatedBy;
	sf::Text* txtContinue;
};
