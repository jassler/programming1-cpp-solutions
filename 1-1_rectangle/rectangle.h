#ifndef H_RECTANGLE
#define H_RECTANGLE

class Rectangle
{
public:
    unsigned int width;
    unsigned int height;

    char border = '#';
    char fill = ' ';

    Rectangle(unsigned int _width, unsigned int _height);

    void draw();
    void grow();
    void shrink();
    unsigned int area();
    unsigned int circumference();
};

#endif