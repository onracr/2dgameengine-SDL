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

    public:
        int ticksLastFrame;
        static SDL_Renderer *renderer;
        Game();
        ~Game();
        void Initialize(int, int);
        void LoadLevel(int);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
        bool IsRunning() const;
        void GetEntityNames() const;
};

#endif
