#ifndef DIMENSION_H
#define DIMENSION_H

#include "SDL2/SDL.h"

namespace TitanRTS
{
    struct DimensionStruct
    {
        int width;
        int height;
    };

    class Dimension
    {
    public:
        Dimension(void);
        Dimension(DimensionStruct *dim);
        Dimension(Dimension *dim);
        Dimension(int m_width, int m_height);
        virtual ~Dimension();

        virtual bool isEmpty(void);
        int getWidth(void);
        int getHeight(void);
        DimensionStruct *getDimensionStruct(void);

    protected:
        int width;
        int height;
    };
}

#endif