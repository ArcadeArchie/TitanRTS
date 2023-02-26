#include "Core/Surface.h"
#include "SDL2/SDL_image.h"

namespace TitanRTS
{
    Surface::Surface()
    {
        releaseSurface = true;
        empty = true;
        width = 0;
        height = 0;
        surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    }
    Surface::Surface(int m_width, int m_height)
    {
        releaseSurface = true;
        empty = false;
        width = m_width;
        height = m_height;
        surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    }
    Surface::Surface(SDL_Surface *surf)
    {
        releaseSurface = false;
        if (surf != nullptr)
        {
            surface = surf;
            empty = false;
            width = surf->w;
            height = surf->h;
        }
    }
    Surface::Surface(std::string m_path)
    {
        releaseSurface = true;
        empty = true;
        width = 0;
        height = 0;

        surface = IMG_Load(m_path.c_str());

        if (surface)
        {
            empty = false;
            width = surface->w;
            height = surface->h;
        }
    }

    void Surface::setRelease(bool release)
    {
        releaseSurface = release;
    }

    void Surface::freeSurface(void)
    {
        if (!(releaseSurface && surface != nullptr && width > 0 && height > 0))
            return;
        SDL_FreeSurface(surface);
        width = 0;
        height = 0;
        empty = true;
        surface = nullptr;
    }

    Surface::~Surface()
    {
    }
}