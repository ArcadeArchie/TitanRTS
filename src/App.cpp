#include "App.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "Core/Config/AppConfig.h"

using namespace Core;

void App::Run()
{
    Config::AppConfig cfg = Config::AppConfig::from_file("assets/appCfg.ini");
    SDL_Event e;
    int quitSig = std::stoi(cfg["QuitSig"]);
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == quitSig)
                quit = true;
        }
    }
}

bool App::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    gWindow = SDL_CreateWindow("TitanRTS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 400, SDL_WINDOW_SHOWN);
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