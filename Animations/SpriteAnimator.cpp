
#include "SpriteAnimator.h"

SpriteAnimator::SpriteAnimator()
{
}

void SpriteAnimator::UpdateAnimation()
{
    if (this->FrameCount >= 1)
    {
        this->FrameIndex++;
        this->FrameCount = 0;

        if (this->FrameIndex == 4)
        {
            this->FrameIndex = 0;
        }
    }

    this->FrameCount += this->FrameSpeed;
}

void SpriteAnimator::DrawAnimation(sf::RenderWindow* window)
{
    window->draw(Sprites[this->FrameIndex]);
}

SpriteAnimator::~SpriteAnimator()
{
}