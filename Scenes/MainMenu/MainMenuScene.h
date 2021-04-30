
#include "../Scene.h"
#include "../SceneManager.h"
#include "../Utils/TextUtils.h"
#include "../Utils/SpriteUtils.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MainMenuScene : public Scene
{
public:
	MainMenuScene(sf::Font *font);
	~MainMenuScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void Reset();
	void HandleInput(sf::Event* event);

private:
	sf::Sprite* sprApple;
	sf::Text *txtNewGame;
	sf::Text *txtLoadGame;
	sf::Text *txtCredits;
	sf::Text *txtOptions;
	sf::Text *txtExit;
	int menuPointer = 0;

	sf::SoundBuffer bufferSfxEat;
	sf::SoundBuffer bufferSfxEatReverse;
	sf::Sound soundSfxEat;
	sf::Sound soundSfxEatReverse;
};
