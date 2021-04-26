#pragma once

#include "../../Scene.h"
#include "../../../Utils/TextUtils.h"
#include "../../SceneManager.h"

#include <SFML/Graphics.hpp>

class ExitScene : public Scene
{
public:
	ExitScene(sf::Font *font);
	~ExitScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleInput();

private:
	sf::Text *txtAreYouSure;
};

