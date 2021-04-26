
#include "../../Scene.h"
#include "../../SceneManager.h"
#include "../../../Utils/TextUtils.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CreditsScene : public Scene 
{
public:
	CreditsScene(sf::Font *font);
	~CreditsScene();
	void Update();
	void Draw(sf::RenderWindow* window);
	void HandleInput();

private:
	sf::Text *txtCreatedBy;
	sf::Text *txtCreatedByValue;
	sf::Text *txtCreatedYear;
	sf::Text* txtEmail;
};