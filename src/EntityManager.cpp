#include "EntityManager.h"
#include "Entity.h"
#include "Collision.h"
#include "Components/ColliderComponent.h"

#include <iostream>

void EntityManager::ClearData()
{
    for (auto& entity : entities)
    {
        entity->Destroy();
    }   
}

bool EntityManager::HasNoEntities()
{
    return entities.size() == 0;
}

void EntityManager::Update(float deltaTime)
{
    for (auto& entity : entities)
    {
        entity->Update(deltaTime);
    }
    DestroyInactiveEntities();
}

void EntityManager::DestroyInactiveEntities()
{
    for (int i = 0; i < entities.size(); i++)
    {
	if (!entities[i]->IsActive())
	{
	    entities.erase(entities.begin() + i);
	}
    }
}

void EntityManager::Render()
{
    for (int layerNumber = 0; layerNumber < NUM_LAYERS; layerNumber++) {
	for (auto& entity : GetEntitiesByLayer(static_cast<LayerType>(layerNumber)))
	{
	    entity->Render();
	}
    }
}

Entity& EntityManager::AddEntity(std::string entityName, LayerType layer)
{
    Entity* entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() const
{
    return entities;
}

std::vector<Entity*> EntityManager::GetEntitiesByLayer(LayerType layer) const
{
    std::vector<Entity*> selectedEntities;
    for (auto& entity : entities)
    {
	if (entity->layer == layer)
	    selectedEntities.emplace_back(entity);
    }
    return selectedEntities; 
}

unsigned int EntityManager::GetEntityCount()
{
    return entities.size();
}

void EntityManager::ListAllEntities() const
{
    unsigned int i {};
    for (auto& entity : entities)
    {
	std::cout << "Entity[" << i << "]" << entity->name << std::endl;
	entity->ListAllComponents();
	i++;
    }
}

CollisionType EntityManager::CheckCollisions() const
{
    for (int i = 0 ; i < entities.size() - 1; i++)
    {
	auto& entity = entities[i];
	if (entity->HasComponent<ColliderComponent>())
	{
	    ColliderComponent* collider = entity->GetComponent<ColliderComponent>();
	    for (int j = i + 1; j < entities.size(); j++)
	    {
		auto& otherEntity = entities[j];
		if (entity->name.compare(otherEntity->name) != 0 && otherEntity->HasComponent<ColliderComponent>())
		{
		    ColliderComponent* otherCollider = otherEntity->GetComponent<ColliderComponent>();
		    if (Collision::CheckRectangleCollision(collider->collider, otherCollider->collider))
		    {
			if (collider->colliderTag.compare("PLAYER") == 0 && otherCollider->colliderTag.compare("ENEMY") == 0)
			{
			    return PLAYER_ENEMY_COLLISION;
			}
			if (collider->colliderTag.compare("PLAYER") == 0 && otherCollider->colliderTag.compare("PROJECTILE") == 0)
			{
			    return PLAYER_PROJECTILE_COLLISION;
			}
			if (collider->colliderTag.compare("ENEMY") == 0 && otherCollider->colliderTag.compare("FRIENDLY_PROJECTILE") == 0)
			{
			    return ENEMY_PROJECTILE_COLLISION;
			}
			if (collider->colliderTag.compare("PLAYER") == 0 && otherCollider->colliderTag.compare("LEVEL_COMPLETE") == 0)
			{
			    return PLAYER_LEVEL_COMPLETE_COLLISION;
			}
		    }
		}
	    }
	}
    }
    return NO_COLLISION;
}
