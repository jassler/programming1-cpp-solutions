#include <iostream>
#include <limits>
#include "rectangle.h"

// "uint" from now on counts as the keyword "unsigned int"
typedef unsigned int uint;

Rectangle::Rectangle(uint _width, uint _height)
{
    width = _width;
    height = _height;
}

bool is_border(uint x, uint y, Rectangle rect)
{
    return 
        x == 0 ||
        y == 0 ||
        x == rect.width - 1 ||
        y == rect.height - 1;
}

void Rectangle::draw()
{
    for(uint y = 0; y < height; y++)
    {
        for(uint x = 0; x < width; x++)
        {
            if(is_border(x, y, *this))
                std::cout << border;
            else
                std::cout << fill;
        }
        std::cout << '\n';
    }
}

void Rectangle::grow()
{
    // maximum number for an unsigned integer to reach
    // should be somewhere around 2^32-1
    uint max = std::numeric_limits<uint>::max();

    if(width < max && height < max)
    {
        width++;
        height++;
    }
}

void Rectangle::shrink()
{
    if(width > 0 && height > 0)
    {
        width--;
        height--;
    }
}

uint Rectangle::area()
{
    return width * height;
}

uint Rectangle::circumference()
{
    return 2 * (width + height);
}
