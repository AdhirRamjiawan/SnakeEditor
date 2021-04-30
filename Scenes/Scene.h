
#pragma once

#include "../Console/Console.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update();
	virtual void Draw(sf::RenderWindow* window);
	virtual void Reset();
	virtual void HandleInput(sf::Event* event);
	std::string GetName();
	void SetName(std::string name);
	Console* DevConsole;

private:
	std::string sceneName;
};