
#pragma once

#include "Scene.h"

class SceneManager
{
public:
	static SceneManager* GetInstance();
	~SceneManager();
	void AddScene(Scene *scene);
	void SetCurrentScene(std::string sceneName);
	Scene *GetCurrentScene();

private:
	SceneManager();
	std::vector<Scene*> scenes;
	Scene* currentScene;
	static inline SceneManager* instance;
};
