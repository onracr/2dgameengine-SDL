#include "FontManager.h"
#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

TTF_Font* FontManager::LoadFont(const char* fileName, int fontSize)
{
    return TTF_OpenFont(fileName, fontSize);
}

void FontManager::Draw(SDL_Texture* texture, SDL_Rect position)
{
    SDL_RenderCopy(Game::renderer, texture, NULL, &position);
}
