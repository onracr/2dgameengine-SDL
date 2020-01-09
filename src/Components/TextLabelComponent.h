#ifndef TEXTLABELCOMPONENT_H
#define TEXTLABELCOMPONENT_H

#include "../Component.h"
#include "../Game.h"
#include "../FontManager.h"
#include "../AssetManager.h"

class TextLabelComponent : public Component
{
    private:
	SDL_Rect position;
	SDL_Color color;
	SDL_Texture* texture;
	std::string text;
	std::string fontFamily;

    public:
	
	TextLabelComponent(int x, int y, std::string text, std::string fontFamily, const SDL_Color& color)
	{
	    this->position.x = x;
	    this->position.y = y;
	    this->text = text;
	    this->fontFamily = fontFamily;
	    this->color = color;
	    SetLabelText(text, fontFamily);
	}

	void SetLabelText(std::string text, std::string fontFamily)
	{
	    SDL_Surface* surface = TTF_RenderText_Blended(Game::assetManager->GetFont(fontFamily), text.c_str(), color);
	    texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	    SDL_FreeSurface(surface);
	    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
	}

	void Render() override
	{
	    FontManager::Draw(texture, position);
	}
};

#endif 
