#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

typedef unsigned int uint;

const uint WINDOW_WIDTH = 800;
const uint WINDOW_HEIGHT = 600;

const uint FPS = 60;
const uint FRAME_TARGET_TIME = 1000 / FPS;

enum CollisionType
{
    NO_COLLISION,
    PLAYER_ENEMY_COLLISION,
    PLAYER_PROJECTILE_COLLISION,
    ENEMY_PROJECTILE_COLLISION,
    PLAYER_VEGETATION_COLLISION,
    PLAYER_LEVEL_COMPLETE_COLLISION
};

enum LayerType
{
    TILEMAP_LAYER = 0,
    VEGETATION_LAYER = 1,
    ENEMY_LAYER = 2,
    OBSTACLE_LAYER = 3,
    PLAYER_LAYER = 4,
    PROJECTILE_LAYER = 5,
    UI_LAYER = 6
};

const uint NUM_LAYERS = 7;
const SDL_Color WHITE_COLOR = {255, 255, 255, 255};
const SDL_Color GREEN_COLOR = {0, 255, 0, 255};

#endif
