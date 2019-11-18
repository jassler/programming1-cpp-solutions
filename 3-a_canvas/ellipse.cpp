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
}

void Ellipse::draw()
{
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
				std::cout << get_fill();
			else
				std::cout << ' ';
		}
		std::cout << '\n';
	}
}

double Ellipse::area()
{
	return M_PI * get_width() * get_height() / 4;
}
