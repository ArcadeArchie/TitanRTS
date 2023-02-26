#ifndef COLOR_H
#define COLOR_H

#include "SDL2/SDL.h"

namespace TitanRTS
{
    class Color
    {
    public:
        Color();
        Color(Uint8 r, Uint8 g, Uint8 b);
        Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        ~Color();

        void mapColor(SDL_PixelFormat *format);
        SDL_Color asSDL();

    protected:
        Uint8 red;
        Uint8 blue;
        Uint8 green;
        Uint8 alpha;
        Uint32 map;
        bool mapped;
    };
}

#endif