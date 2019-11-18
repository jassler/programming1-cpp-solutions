// this define is needed for windows to use cmath constants
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include <cmath>	// M_PI
#include "ellipse.h"
#include "rectangle.h"

Ellipse::Ellipse(int _width, int _height, char _fill)
	: Shape(_width, _height, _fill)
{
	resize(_width, _height);
}

void Ellipse::draw()
{
	for (auto& line : drawn_ellipse)
		std::cout << line << '\n';
}

double Ellipse::area()
{
	return M_PI * get_width() * get_height() / 4;
}

char Ellipse::char_at(Point p)
{
	if (p.x < 0 || p.x >= get_width())
		return 0;
	if (p.y < 0 || p.y >= get_height())
		return 0;
	return drawn_ellipse[p.y][p.x];
}

void Ellipse::resize(int new_width, int new_height)
{
	// make sure width / height gets updated
	Shape::resize(new_width, new_height);
	drawn_ellipse.clear();

	if (new_width <= 0 || new_height <= 0)
		return;

	drawn_ellipse.resize(new_height, std::string(new_width, ' '));

	double center_x = get_width() / 2.0;
	double center_y = get_height() / 2.0;

	double width_sq = center_x * center_x;
	double height_sq = center_y * center_y;

	for (int y = 0; y < get_height(); y++)
	{
		for (int x = 0; x < get_width(); ++x)
		{
			double d_x = (double)x - center_x;
			double d_y = (double)y - center_y;

			if (d_x * d_x / width_sq + d_y * d_y / height_sq <= 1)
				drawn_ellipse[y][x] = get_fill();
			else
				drawn_ellipse[y][x] = ' ';
		}
	}
}
