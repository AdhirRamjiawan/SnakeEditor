
#include "../Scene.h"
#include "../../Animations/GameOver/DyingSnakeAnimator.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameOverScene : public Scene 
{
public:
	GameOverScene(sf::Font font, float gameWidth, float gameHeight);
	~GameOverScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput();
	sf::Text txtGameOver;
	sf::Text txtGameOverInstructions;

private:
	sf::Font font;
	float gameWidth, gameHeight;
	DyingSnakeAnimator *dyingSnakeAnimation;
};