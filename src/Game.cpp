#include <iostream>
#include "Entity.h"
#include "Constants.h"
#include "Game.h"
#include "Components/TransformComponent.h"
#include "../lib/glm/glm.hpp"

SDL_Renderer* Game::renderer;
EntityManager manager;

void Game::GetEntityNames() const
{
    for (auto& entity : manager.GetEntities())
    {
        std::cout << entity->name << std::endl;
        for(auto& component : entity->GetComponents())
        {
            std::cout << "\t" << component->componentName << std::endl;
        }
    }
}

Game::Game()
{
    isRunning = false;
}

Game::~Game()
{}

bool Game::IsRunning() const
{
    return isRunning;
}

void Game::Initialize(int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }
    window = SDL_CreateWindow
        (
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_BORDERLESS
        );

    if (!window)
    {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cerr << "Error creating SDL renderer." << std::endl;
    }
    LoadLevel(0);
    isRunning = true;
    
    return;
}

void Game::LoadLevel(int levelNumber)
{
    Entity& entity(manager.AddEntity("projectile"));
    Entity& entity_2(manager.AddEntity("projectile_2"));
    auto& entity_3(manager.AddEntity("projectile_3"));
    auto& entity_4(manager.AddEntity("projectile_4"));
    entity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
    entity_2.AddComponent<TransformComponent>(768, 0, -20, 20, 32, 32, 1);
    entity_3.AddComponent<TransformComponent>(0, 568, 20, -20, 32, 32, 1);
    entity_4.AddComponent<TransformComponent>(768, 568, -20, -20, 32, 32, 1);
}

void Game::ProcessInput()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                isRunning = false;
            break;
        default:
            break;
    }
}

void Game::Update()
{
    // Wait until 16ms has elapsed since the last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));

    // DeltaTime is the difference int ticks from last frame converted to seconds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.f;

    // Clamp deltaTime to a max value
    deltaTime = (deltaTime > .05f) ? .05f : deltaTime;

    // Sets the new ticks for the current frame to be used in the next pass
    ticksLastFrame = SDL_GetTicks();

    manager.Update(deltaTime);
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    if (manager.HasNoEntities()) return;
    manager.Render();

    SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
