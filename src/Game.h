#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game
{
    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        int ticksLastFrame;
        Game();
        ~Game();
        void Initialize(int, int);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
        bool IsRunning() const;
};

#endif