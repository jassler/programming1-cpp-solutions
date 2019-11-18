#include "shape.h"

Shape::Shape(int _width, int _height, char _fill)
	: width(_width), height (_height), fill(_fill)
{
}

void Shape::resize(int new_width, int new_height)
{
	this->width = new_width;
	this->height = new_height;
}

int Shape::get_width()
{
	return width;
}

int Shape::get_height()
{
	return height;
}

char Shape::get_fill()
{
	return fill;
}
