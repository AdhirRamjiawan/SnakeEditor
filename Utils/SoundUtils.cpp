
#include "SoundUtils.h"

SoundUtils::SoundUtils()
{
}

SoundUtils::~SoundUtils()
{
}

void SoundUtils::PlaySfx(sf::Sound* sound)
{
	if (GameState::Config.PlaySfx)
	{
		sound->play();
	}
}

void SoundUtils::StopSfx(sf::Sound* sound)
{
	if (GameState::Config.PlaySfx)
	{
		sound->stop();
	}
}

void SoundUtils::PlayMusic(sf::Sound* music)
{
	if (GameState::Config.PlayMusic)
	{
		music->play();
	}
}

void SoundUtils::StopMusic(sf::Sound* music)
{
	if (GameState::Config.PlayMusic)
	{
		music->stop();
	}
}

