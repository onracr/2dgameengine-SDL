#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "./Game.h"

class TextureManager
{
    public:
	static SDL_Texture* LoadTexture(const char*);
	static void Draw(SDL_Texture*, SDL_Rect, SDL_Rect, SDL_RendererFlip);
};

#endif 
