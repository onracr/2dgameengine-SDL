#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class AssetManager;

class Game
{
    private:
        bool isRunning;
        SDL_Window *window;
	class TransformComponent* transform;

    public:
        int ticksLastFrame;
        static SDL_Renderer *renderer;
	static AssetManager* assetManager;
	static SDL_Event event;
	static SDL_Rect camera;

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
	void HandleCameraMovement();
	void CheckCollisions();
	void ProcessNextLevel(int);
	void ProcessGameOver();
};

#endif
