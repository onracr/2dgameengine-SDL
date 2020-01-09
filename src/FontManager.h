#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SDL2/SDL_ttf.h>

class FontManager
{
    public:
	static TTF_Font* LoadFont(const char* fileName, int fontSize);
	static void Draw(class SDL_Texture* texture, class SDL_Rect position);
};

#endif 
