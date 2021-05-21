
#include "SceneManager.h"

SceneManager::SceneManager(void* a)
{
	if (a == NULL)
	{
		std::cout << "SceneManager should not be instantiated outside of this class." << std::endl;
		exit(0);
	}

	font = std::make_shared<sf::Font>();
	if (!font->loadFromFile("gaming.ttf"))
	{
		std::cout << "cannot find gaming.ttf" << std::endl;
		exit(0);
	}
	
	this->scenes.push_back(std::make_unique<SplashScene>(font));
	this->scenes.push_back(std::make_unique<CreditsScene>(font));
	this->scenes.push_back(std::make_unique<MainMenuScene>(font));
	this->scenes.push_back(std::make_unique<ExitScene>(font));
	this->scenes.push_back(std::make_unique<GameScene>(font));
	this->scenes.push_back(std::make_unique<GameOverScene>(font));
	this->scenes.push_back(std::make_unique<LeaderboardScene>(font));
}

SceneManager* SceneManager::GetInstance()
{
	if (!instance)
		instance = std::make_unique<SceneManager>((void *)123);
	return instance.get();
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetCurrentScene(std::string sceneName)
{
	for (auto &scene : this->scenes)
	{
		if (scene->GetName() == sceneName)
		{
			this->currentScene = scene.get();
			break;
		}
	}
}

Scene *SceneManager::GetCurrentScene()
{
	return this->currentScene;
}
