
#include "../Scene.h"
#include "../SceneManager.h"
#include "../Utils/TextUtils.h"
#include "../Utils/SpriteUtils.h"

#include <SFML/Graphics.hpp>

class MainMenuScene : public Scene
{
public:
	MainMenuScene(sf::Font *font);
	~MainMenuScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleInput();

private:
	sf::Sprite* sprApple;
	sf::Text *txtNewGame;
	sf::Text *txtLoadGame;
	sf::Text *txtCredits;
	sf::Text *txtOptions;
	sf::Text *txtExit;
	int menuPointer = 0;
};
