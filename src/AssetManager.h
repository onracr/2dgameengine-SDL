#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>

class AssetManager
{
    private:
	class EntityManager* manager;
	std::map<std::string, class SDL_Texture*> textures;	
    public:
	AssetManager(EntityManager*);
	~AssetManager();
	
	void ClearData();
	void AddTexture(std::string, const char*);
	SDL_Texture* GetTexture(std::string);
};

#endif
