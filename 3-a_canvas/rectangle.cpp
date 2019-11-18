#include <iostream>
#include <string>
#include "rectangle.h"

Rectangle::Rectangle(int _width, int _height, char _border, char _fill)
	: Shape(_width, _height, _fill), border(_border)
{
}

bool Rectangle::is_border(int x, int y)
{
	if (x == 0 || y == 0)
		return true;
	if (x == get_width() - 1 || y == get_height() - 1)
		return true;

	return false;
}

void Rectangle::draw()
{
	for (int y = 0; y < get_height(); y++)
	{
		for (int x = 0; x < get_width(); x++)
		{
			if (is_border(x, y))
				std::cout << get_border();
			else
				std::cout << get_fill();
		}
		std::cout << '\n';
	}
}

char Rectangle::get_border()
{
	return border;
}

double Rectangle::area()
{
	return get_width() * get_height();
}
