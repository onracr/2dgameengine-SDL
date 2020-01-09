#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../../lib/glm/glm.hpp"
#include "../Component.h"
#include "../Constants.h"

class TransformComponent : public Component
{
    public:
        glm::vec2 position;
        glm::vec2 velocity;
        int width;
        int height;
        int scale;

    private:
	const float clampValue {5.f};	

    public:	
        TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
        {
            position = glm::vec2(posX, posY);
            velocity = glm::vec2(velX, velY);
            width = w;
            height = h;
            scale = s;
        }
        
        void Update(float deltaTime) override
        {
            position.x += velocity.x * deltaTime;
            position.y += velocity.y * deltaTime;
        }

	bool BoundsCheckX(const float x) const
	{
	    return x >= WINDOW_WIDTH - clampValue;
	}

	bool BoundsCheck_X(const float x) const
	{
	    return x <= clampValue;
	}

	bool BoundsCheckY(const float y) const
	{
	    return y >= WINDOW_HEIGHT - clampValue;
	}

	bool BoundsCheck_Y(const float y) const
	{
	    return y <= clampValue;
	}
};

#endif
