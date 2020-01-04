#ifndef ENTITY_H
#define ENTITY_H

#include "EntityManager.h"
#include <vector>
#include <string>
#include <typeinfo>

class Entity
{
    private:
        class EntityManager& manager;
        std::vector<class Component*> components;
        bool isActive;
        
    public:
        std::string name;

        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        
        void Update(float);
        void Render();
        void Destroy();
        bool IsActive() const;

        std::vector<Component*> GetComponents() const
        {
            return components;
        }

        template <typename T, typename... TArgs>
        T &AddComponent(TArgs&&... args)
        {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->componentName = typeid(T).name();
            newComponent->owner = this;
            components.emplace_back(newComponent);
            newComponent->Initialize();

            return *newComponent;
        }
};

#endif
