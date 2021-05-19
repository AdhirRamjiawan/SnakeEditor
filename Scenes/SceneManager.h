
#pragma once

#include "Scene.h"
#include "../Scenes/GameOver/GameOverScene.h"
#include "../Scenes/Game/GameScene.h"
#include "../Scenes/Splash/SplashScene.h"
#include "../Scenes/MainMenu/MainMenuScene.h"
#include "../Scenes/MainMenu/Credits/CreditsScene.h"
#include "../Scenes/MainMenu/Exit/ExitScene.h"
#include "../Scenes/Leaderboard/LeaderboardScene.h"

class SceneManager
{
public:
	static SceneManager* GetInstance();
	~SceneManager();
	void SetCurrentScene(std::string sceneName);
	Scene *GetCurrentScene();
	SceneManager(void *a = NULL);
	
private:
	std::vector<std::unique_ptr<Scene>> scenes;
	Scene* currentScene;
	static inline std::unique_ptr<SceneManager> instance;
	std::shared_ptr<sf::Font> font;
};
