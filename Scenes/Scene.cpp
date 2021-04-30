
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Update()
{
}

void Scene::Reset()
{

}

void Scene::Draw(sf::RenderWindow* window)
{
}

void Scene::HandleEvent(sf::Event* event)
{

}

void Scene::HandleInput()
{
}

std::string Scene::GetName()
{
    return this->sceneName;
}

void Scene::SetName(std::string name)
{
    this->sceneName = name;
}
