#include <iostream>
#include "Entity.h"
#include "Constants.h"
#include "Game.h"
#include "AssetManager.h"
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;
AssetManager* Game::assetManager = new AssetManager(&manager);


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
    /** Start including new assets to the assetmanager map */
    std::string textureFilePath = "./assets/images/tank-big-right.png";
    assetManager->AddTexture("tank-img" , textureFilePath.c_str());
    /** Start including entities and also components to them */
    
    Entity& entity(manager.AddEntity("tank"));
    entity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
    entity.AddComponent<SpriteComponent>("tank-img");
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
