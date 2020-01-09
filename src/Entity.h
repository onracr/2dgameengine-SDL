#ifndef ENTITY_H
#define ENTITY_H

#include "EntityManager.h"
#include "Constants.h"
#include <vector>
#include <string>
#include <map>
#include <typeinfo>
#include <iostream>

class Entity
{
    private:
        class EntityManager& manager;
        std::vector<class Component*> components;
	std::map<const std::type_info*, Component*> componentTypeMap;
        bool isActive;
        
    public:
	std::string name;
	LayerType layer;

        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name, LayerType layer);
        
        void Update(float);
        void Render();
        void Destroy();
	void ListAllComponents() const;
        bool IsActive() const;

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args)
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

	template<typename T> 
	bool HasComponent() const
	{
	    // return componentTypeMap.count(&typeid(T)); can simply use to check condition
	    for (auto& mapElement : componentTypeMap)
	    {
		if (mapElement.first->name() == typeid(T).name()) return true;
	    }

	    return false;
	}
};

#endif
