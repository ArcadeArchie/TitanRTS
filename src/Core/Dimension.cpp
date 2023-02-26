#include "Core/Dimension.h"

namespace TitanRTS
{
    Dimension::Dimension(void)
    {
        width = 0;
        height = 0;
    }
    Dimension::Dimension(DimensionStruct *dim)
    {
        width = dim->width;
        height = dim->height;
    }
    Dimension::Dimension(Dimension *dim)
    {
        width = dim->getWidth();
        height = dim->getHeight();
    }
    Dimension::Dimension(int m_width, int m_height)
    {
        width = m_width;
        height = m_height;
    }

    bool Dimension::isEmpty(void)
    {
        return (width == 0 && height == 0);
    }
    
    int Dimension::getWidth(void) { return width; }
    int Dimension::getHeight(void) { return height; }

    DimensionStruct* Dimension::getDimensionStruct(void)
    {
        DimensionStruct *dim = new DimensionStruct();
        dim->width = width;
        dim->height = height;
        return dim;
    }

    Dimension::~Dimension(){}
}