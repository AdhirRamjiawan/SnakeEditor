
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Scene
{
public:
	Scene();
	~Scene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleInput();

private:

};