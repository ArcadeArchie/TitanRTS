#include "SDL2/SDL.h"

class App
{
private:
    bool quit = false;
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = nullptr;
public:
    bool Init();
    void Close();
    void Run();
};
