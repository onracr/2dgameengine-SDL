#include "Animation.h"


Animation::Animation() {}

Animation::Animation(uint index, uint numFrames, uint animationSpeed) 
{
    this->index = index;
    this->numFrames = numFrames;
    this->animationSpeed = animationSpeed;
}


