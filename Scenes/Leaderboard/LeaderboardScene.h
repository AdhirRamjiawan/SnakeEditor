#pragma once

#include "../Scene.h"
#include "../SceneManager.h"
#include "../Utils/TextUtils.h"
#include "../Utils/SpriteUtils.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class LeaderboardScene : public Scene
{
public:
	LeaderboardScene();
	~LeaderboardScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleEvent(sf::Event* event);
	void HandleInput();


private:

};
