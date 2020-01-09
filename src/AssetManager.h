#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include <SDL2/SDL_ttf.h>

class AssetManager
{
    private:
	class EntityManager* manager;
	std::map<std::string, class SDL_Texture*> textures;	
	std::map<std::string, TTF_Font*> fonts;
    public:
	AssetManager(EntityManager*);
	~AssetManager();
	
	void ClearData();
	void AddTexture(std::string, const char*);
	void AddFont(std::string, const char*, int);
	SDL_Texture* GetTexture(std::string);
	TTF_Font* GetFont(std::string fontId);
};

#endif
