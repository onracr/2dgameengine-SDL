#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <SDL2/SDL.h>
#include "Game.h"
#include "Entity.h"

class Component
{
    public:
		std::string componentName;
		Entity* owner;
	
		virtual ~Component() {}
		virtual void Initializer() {}
		virtual void Update(float) {}
		virtual void Render() {}
};

#endif
