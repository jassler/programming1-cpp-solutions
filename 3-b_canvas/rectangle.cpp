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

char Rectangle::char_at(Point p)
{
	if (p.x < 0 || p.x >= get_width())
		return 0;
	if (p.y < 0 || p.y >= get_height())
		return 0;
	return is_border(p.x, p.y) ? border : get_fill();
}

void Rectangle::resize(int new_width, int new_height)
{
	Shape::resize(new_width, new_height);
}

char Rectangle::get_border()
{
	return border;
}

double Rectangle::area()
{
	return (double) get_width() * get_height();
}
