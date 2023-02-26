#include "Core/Color.h"

namespace TitanRTS
{

    Color::Color()
    {
        red = 0;
        green = 0;
        blue = 0;
        mapped = false;
    }
    Color::Color(Uint8 r, Uint8 g, Uint8 b)
    {
        red = r;
        green = g;
        blue = b;
        alpha = 255;
        mapped = false;
    }
    Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        red = r;
        green = g;
        blue = b;
        alpha = a;
        mapped = false;
    }

    void Color::mapColor(SDL_PixelFormat *format)
    {
        if (mapped)
            return;
        map = SDL_MapRGBA(format, red, green, blue, alpha);
        mapped = true;
    }
}