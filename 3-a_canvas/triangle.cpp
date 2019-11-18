#include <iostream>
#include "triangle.h"

Triangle::Triangle(int _width, int _height, char _fill)
	: Shape(_width, _height, _fill)
{
}

void Triangle::draw()
{
	bool is_width_even = (get_width() % 2) == 0;

	for (int y = 0; y < get_height(); y++)
	{
		double ratio = ((double) y + 1.0) / get_height();
		int row_width = (int) (get_width() * ratio);

		// for better symmetry, make sure size always changes by 2
		if (row_width % 2 == 1 && is_width_even)
			row_width++;
		else if (row_width % 2 == 0 && !is_width_even)
			row_width++;


		// amount of whitespace before we can print the fill
		int start = (get_width() - row_width) / 2;

		std::cout << std::string(start, ' ');
		std::cout << std::string(row_width, get_fill());
		std::cout << '\n';
	}
}

double Triangle::area()
{
	// triangle has two same sides (gleichschenklig)
	return (double) get_width() * get_height() / 2.0;
}
