#include "Core/Font.h"
#include "Core/Surface.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

namespace TitanRTS
{
    Font::Font()
    {
        font = NULL;
        size = -1;
        path = "";
    }
    Font::Font(const char *m_path, int m_size)
    {
        size = m_size;
        path = m_path;
        font = TTF_OpenFont(m_path, m_size);
    }

    Font::Font(SDL_RWops *rw, int m_size)
    {
        font = 0;
        size = m_size;
        path = "rw_ops";
        font = TTF_OpenFontRW(rw, 1, size);
    }

    Font::~Font()
    {
        if (font == NULL)
            return;
        TTF_CloseFont(font);
    }

    int Font::getSize()
    {
        return size;
    }
    const char *Font::getPath()
    {
        return path;
    }

    TTF_Font *Font::getFont()
    {
        return font;
    }

    Surface *Font::renderText(std::string caption, Color *color)
    {
        return renderText(caption.c_str(), color);
    }

    Surface *Font::renderText(const char* text, Color *color)
    {
        SDL_Surface *tex = TTF_RenderText_Solid(font, text, color->asSDL());
        Surface *surf = new Surface(tex);
        surf->setRelease(true);

        return surf;
    }
}