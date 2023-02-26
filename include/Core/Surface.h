#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include "SDL2/SDL.h"

namespace TitanRTS
{
    class Surface
    {
    public:
        Surface();
        Surface(int m_width, int m_height);
        Surface(SDL_Surface *m_surf);
        Surface(std::string m_path);

        void setRelease(bool release);
        void freeSurface(void);

        ~Surface(void);
    protected:
        SDL_Surface *surface = nullptr;
        bool empty;
        bool releaseSurface;
        int width;
        int height;
    };
}

#endif