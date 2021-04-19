
#include "../Scene.h"
#include "../../Animations/GameOver/DyingSnakeAnimator.h"
#include "../Scenes/Game/GameScene.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameOverScene : public Scene 
{
public:
	GameOverScene(GameScene *gameScene, sf::Font font, float gameWidth, float gameHeight);
	~GameOverScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput();
	sf::Text txtGameOver;
	sf::Text txtGameOverInstructions;

private:
	GameScene* gameScene;
	sf::Font font;
	float gameWidth, gameHeight;
	DyingSnakeAnimator *dyingSnakeAnimation;
};