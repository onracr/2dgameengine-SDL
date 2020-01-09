#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include "Constants.h"
#include <vector>
#include <string>

class EntityManager
{
    private:
        std::vector<class Entity*> entities;
    public:
        void ClearData();
        void Update(float);
        void Render();
        bool HasNoEntities();
        Entity& AddEntity(std::string entityName, LayerType layer);
        std::vector<Entity*> GetEntities() const;
	std::vector<Entity*> GetEntitiesByLayer(LayerType layer) const;
        unsigned int GetEntityCount();
	void ListAllEntities() const;
	CollisionType CheckCollisions() const;
	void DestroyInactiveEntities();
};

#endif
