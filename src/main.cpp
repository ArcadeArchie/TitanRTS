#define SDL_MAIN_HANDLED
#include "App.h"


int main(int argc, char const *argv[])
{
    App *app = new App();

    if (!app->Init())
        return -1;
    app->Run();

    app->Close();
    
    return 0;
}