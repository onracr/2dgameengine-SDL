#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "TransformComponent.h"
#include "../TextureManager.h"
#include "../Component.h"
#include "../AssetManager.h"
#include <string>

class SpriteComponent : public Component
{
    private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;

    public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;	

	SpriteComponent(const std::string filePath)
	{
	    SetTexture(filePath);
	}

	void SetTexture(std::string assetTextureId)
	{
	    texture = Game::assetManager->GetTexture(assetTextureId);
	}

	void Initializer() override
	{
	    transform = owner->GetComponent<TransformComponent>();
	    sourceRectangle.x = 0;
	    sourceRectangle.y = 0;
	    sourceRectangle.w = transform->width;
	    sourceRectangle.h = transform->height;
	}

	void Update(float deltaTime) override
	{
	    destinationRectangle.x = (int) transform->position.x;
	    destinationRectangle.y = (int) transform->position.y;
	    destinationRectangle.w = transform->width * transform->scale;
	    destinationRectangle.h = transform->height * transform->scale;
	}

	void Render() override
	{
	    TextureManager::Draw(texture, sourceRectangle, destinationRectangle, spriteFlip);
	}
};

#endif 
