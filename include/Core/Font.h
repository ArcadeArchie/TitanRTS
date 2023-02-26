#ifndef FONT_H
#define FONT_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Surface.h"
#include "Color.h"

namespace TitanRTS
{
    class Font
    {
    private:
        TTF_Font *font = nullptr;
        const char *path;
        int size;

    public:
        Font();
        Font(const char *m_path, int m_size);
        Font(SDL_RWops *rw, int m_size);
        ~Font();

        int getSize();
        const char *getPath();
        TTF_Font *getFont();

        Surface* renderText(const char*caption, Color *color);
        Surface* renderText(std::string caption, Color *color);
    };
}

#endif