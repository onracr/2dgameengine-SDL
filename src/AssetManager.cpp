#include "AssetManager.h"
#include "TextureManager.h"
#include "EntityManager.h"

AssetManager::AssetManager(EntityManager* manager)
	: manager(manager)
{
    
}

void AssetManager::ClearData()
{
    textures.clear();
}    

void AssetManager::AddTexture(std::string textureId, const char* filePath)
{
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

SDL_Texture* AssetManager::GetTexture(std::string textureId)
{
    return textures[textureId];
}

