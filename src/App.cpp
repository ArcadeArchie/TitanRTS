#include "App.h"
#include "SDL2/SDL.h"
#include <iostream>


void App::Run()
{
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }
}

bool App::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    gWindow = SDL_CreateWindow("TitanRTS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 900, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
        return false;

    return true;
}

void App::Close()
{
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}