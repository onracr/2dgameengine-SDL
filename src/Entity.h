#ifndef ENTITY_H
#define ENTITY_H

#include "EntityManager.h"
#include <vector>
#include <string>
#include <map>
#include <typeinfo>

class Entity
{
    private:
        class EntityManager& manager;
        std::vector<class Component*> components;
	std::map<const std::type_info*, Component*> componentTypeMap;
        bool isActive;
        
    public:
        std::string name;
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        
        void Update(float);
        void Render();
        void Destroy();
        bool IsActive() const;

        template <typename T, typename... TArgs>
        T &AddComponent(TArgs&&... args)
        {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->componentName = typeid(T).name();
            newComponent->owner = this;
            components.emplace_back(newComponent);
	    componentTypeMap[&typeid(*newComponent)] = newComponent;
            newComponent->Initializer();

            return *newComponent;
        }
	
	template<typename T>
	T* GetComponent()
	{
	    return static_cast<T*>(componentTypeMap[&typeid(T)]);
	}
};

#endif
