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

        bool isMapped(void);
        Uint32 getMap(void);
        Uint8 getRed(void);
        Uint8 getGreen(void);
        Uint8 getBlue(void);
        Uint8 getAlpha(void);
        SDL_Color getAsSDL(void);

        void setRGB(Uint8 m_red, Uint8 m_green, Uint8 m_blue);
        void setRGBA(Uint8 m_red, Uint8 m_green, Uint8 m_blue, Uint8 m_alpha);
        void mapColor(SDL_PixelFormat *format);
        bool equals(Color *b);

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