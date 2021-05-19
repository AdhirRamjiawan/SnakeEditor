#pragma once

#include "../../Scene.h"
#include "../../../Utils/TextUtils.h"
#include "../../SceneManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ExitScene : public Scene
{
public:
	ExitScene(std::shared_ptr<sf::Font> font);
	~ExitScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleEvent(sf::Event* event);
	void HandleInput();

private:
	sf::Text *txtAreYouSure;

	sf::SoundBuffer bufferSfxEat;
	sf::SoundBuffer bufferSfxEatReverse;
	sf::Sound soundSfxEat;
	sf::Sound soundSfxEatReverse;
};

