
#pragma once

#include "../Console/Console.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Scene
{
public:
	virtual void Update();
	virtual void Draw(sf::RenderWindow* window);
	virtual void Reset();
	virtual void HandleEvent(sf::Event* event);
	virtual void HandleInput();
	std::string GetName();
	void SetName(std::string name);
	Console* DevConsole;

protected:
	sf::Shader currentShader;

private:
	std::string sceneName;
};