
#include "SceneManager.h"

SceneManager::SceneManager()
{
	currentScene = NULL;
}

SceneManager* SceneManager::GetInstance()
{
	if (!instance)
		instance = new SceneManager();

	return instance;
}

SceneManager::~SceneManager()
{
	for (auto scene : scenes)
		delete scene;

	delete currentScene;
	delete instance;
}

void SceneManager::AddScene(Scene* scene)
{
	this->scenes.push_back(scene);
}

void SceneManager::SetCurrentScene(std::string sceneName)
{
	for (auto s : this->scenes)
	{
		if (s->GetName() == sceneName)
		{
			this->currentScene = s;
			break;
		}
	}
}

Scene *SceneManager::GetCurrentScene()
{
	return this->currentScene;
}
