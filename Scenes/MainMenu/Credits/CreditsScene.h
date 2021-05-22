
#pragma once

#include "../../Scene.h"
#include "../../SceneManager.h"
#include "../../../Utils/TextUtils.h"
#include "../../../Utils/SoundUtils.h"
#include "../../../State/GameState.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class CreditsScene : public Scene 
{
public:
	CreditsScene(std::shared_ptr<sf::Font> font);
	~CreditsScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleEvent(sf::Event* event);
	void HandleInput();

private:
	sf::Text *txtCreatedBy;
	sf::Text *txtCreatedByValue;
	sf::Text *txtCreatedYear;
	sf::Text* txtEmail;

	sf::SoundBuffer bufferSfxEat;
	sf::SoundBuffer bufferSfxEatReverse;
	sf::Sound soundSfxEat;
	sf::Sound soundSfxEatReverse;
};