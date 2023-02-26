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

    Uint8 Color::getRed(void) { return red; }
    Uint8 Color::getGreen(void) { return green; }
    Uint8 Color::getBlue(void) { return blue; }
    Uint8 Color::getAlpha(void) { return alpha; }

    Uint32 Color::getMap(void) { return map; }

    SDL_Color Color::getAsSDL(void)
    {
        SDL_Color color = SDL_Color();
        color.r = red;
        color.g = green;
        color.b = blue;
        color.a = alpha;
        return color;
    }

    void Color::setRGB(Uint8 m_red, Uint8 m_green, Uint8 m_blue)
    {
        if (red == m_red && green == m_green && blue == m_blue)
            return;

        red = m_red;
        green = m_green;
        blue = m_blue;
        mapped = false;
    }
    void Color::setRGBA(Uint8 m_red, Uint8 m_green, Uint8 m_blue, Uint8 m_alpha)
    {
        if (red == m_red && green == m_green && blue == m_blue && alpha == m_alpha)
            return;

        red = m_red;
        green = m_green;
        blue = m_blue;
        alpha = m_alpha;
        mapped = false;
    }

    void Color::mapColor(SDL_PixelFormat *format)
    {
        if (mapped)
            return;
        map = SDL_MapRGBA(format, red, green, blue, alpha);
        mapped = true;
    }

    bool Color::equals(Color *b)
    {
        return (b->getRed() == red && b->getGreen() == green && b->getBlue() == blue && b->getAlpha() == alpha);
    }
}