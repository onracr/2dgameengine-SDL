#ifndef ANIMATION_H
#define ANIMATION_H

typedef unsigned int uint;

class Animation
{
    public:
	uint index;
	uint numFrames;
	uint animationSpeed;

	Animation();
	Animation(uint index, uint numFrames, uint animationSpeed);
	
};

#endif 
