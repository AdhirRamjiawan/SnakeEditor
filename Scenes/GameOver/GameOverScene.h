
#include "../Scene.h"
#include "../SceneManager.h"
#include "../../Animations/GameOver/DyingSnakeAnimator.h"
#include "../Scenes/Game/GameScene.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../Shaders/FadeOutShader.h"
#include "../Shaders/StandardShader.h"

class GameOverScene : public Scene 
{
public:
	GameOverScene(sf::Font font, float gameWidth, float gameHeight);
	~GameOverScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleEvent(sf::Event* event);
	void HandleInput();
	sf::Text txtGameOver;
	sf::Text txtGameOverInstructions;

private:
	GameScene* gameScene;
	sf::Font font;
	float gameWidth = 0.f;
	float gameHeight = 0.f;
	DyingSnakeAnimator *dyingSnakeAnimation;
	sf::RenderStates renderStates;
};