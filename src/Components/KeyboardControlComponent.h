#ifndef KEYBOARDCONTROLCOMPONENT_H
#define KEYBOARDCONTROLCOMPONENT_H

#include "../Component.h"
#include "../EntityManager.h"
#include "../Game.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include <string>

class KeyboardControlComponent : public Component
{
    public:
	std::string upKey;
	std::string downKey;
	std::string rightKey;
	std::string leftKey;
	std::string shootKey;

	TransformComponent* transform;
	SpriteComponent* sprite;

	KeyboardControlComponent() {}

	KeyboardControlComponent(std::string upKey, std::string rightKey, std::string downKey, std::string leftKey, std::string shootKey)
	{
	    this->upKey = GetSDLKeyStringCode(upKey);   
	    this->rightKey = GetSDLKeyStringCode(rightKey);   
	    this->downKey = GetSDLKeyStringCode(downKey);   
	    this->leftKey = GetSDLKeyStringCode(leftKey);  
	    this->shootKey = GetSDLKeyStringCode(shootKey);   
	}

	std::string GetSDLKeyStringCode(std::string keyCode)
	{
	    if (keyCode.compare("up") == 0) return "1073741906";
	    if (keyCode.compare("down") == 0) return "1073741905";
	    if (keyCode.compare("left") == 0) return "1073741904";
	    if (keyCode.compare("right") == 0) return "1073741903";
	    if (keyCode.compare("space") == 0) return "32";

	    return std::to_string(static_cast<int>(keyCode[0]));
	}

	void Initializer() override
	{
	    transform = owner->GetComponent<TransformComponent>();
	    sprite = owner->GetComponent<SpriteComponent>();
	}

	void Update(float deltaTime) override
	{
	    if (Game::event.type == SDL_KEYDOWN)
	    {
		auto keyCode = std::to_string(Game::event.key.keysym.sym);
		if (keyCode.compare(upKey) == 0) 
		{
		    if (transform->BoundsCheck_Y(transform->position.y)) {
			transform->velocity.y = 0;
			return;
		    }
		    transform->velocity.y = -50;
		    transform->velocity.x = 0;
		    sprite->PlayAnimation("UpAnimation");
		}
		if (keyCode.compare(rightKey) == 0) 
		{
		    if (transform->BoundsCheckX(transform->position.x)) {
			transform->velocity.x = 0;
			return;
		    }
		    transform->velocity.x = 50;
		    transform->velocity.y = 0;
		    sprite->PlayAnimation("RightAnimation");
		}
		if (keyCode.compare(downKey) == 0) 
		{
		    if (transform->BoundsCheckY(transform->position.y)) {
			transform->velocity.y = 0;
			return;
		    }
		    transform->velocity.y = 50;
		    transform->velocity.x = 0;
		    sprite->PlayAnimation("DownAnimation");
		}
		if (keyCode.compare(leftKey) == 0) 
		{
		    if (transform->BoundsCheck_X(transform->position.x)) {
			transform->velocity.x = 0;
			return;
		    }
		    transform->velocity.x = -50;
		    transform->velocity.y = 0;
		    sprite->PlayAnimation("LeftAnimation");
		}
		if (keyCode.compare(shootKey) == 0) {
		    // TODO: 
		    // Shoot projectiles when 'space' key is pressed.
		}
	    }
	    if (Game::event.type == SDL_KEYUP)
	    {
		auto keyCode = std::to_string(Game::event.key.keysym.sym);
		if (keyCode.compare(upKey) == 0) {
		    transform->velocity.y = 0;
		}
		if (keyCode.compare(rightKey) == 0) {
		    transform->velocity.x = 0;
		}
		if (keyCode.compare(downKey) == 0) {
		    transform->velocity.y = 0;
		}
		if (keyCode.compare(leftKey) == 0) {
		    transform->velocity.x = 0;
		}
	    }
	}

};

#endif 
