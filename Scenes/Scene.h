
#pragma once

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
	virtual void HandleInput();
	std::string GetName();
	void SetName(std::string name);

private:
	std::string sceneName;
};