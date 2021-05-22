#pragma once

#include "../State/GameState.h"
#include <SFML/Audio.hpp>

class SoundUtils
{
public:
	SoundUtils();
	~SoundUtils();
	static void PlaySfx(sf::Sound *sound);
	static void StopSfx(sf::Sound *sound);
	static void PlayMusic(sf::Sound* music);
	static void StopMusic(sf::Sound *music);

private:

};