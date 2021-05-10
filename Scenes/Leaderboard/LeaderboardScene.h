#pragma once


#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#include "../Scene.h"
#include "../SceneManager.h"
#include "../../Utils/TextUtils.h"
#include "../../Utils/SpriteUtils.h"
#include "../../Utils/LeaderboardUtils.h"

class LeaderboardScene : public Scene
{
public:
	LeaderboardScene(sf::Font* font);
	~LeaderboardScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleEvent(sf::Event* event);
	void HandleInput();


private:
	std::vector<sf::Text *> entries;
	sf::Text *txtTitle;
};
