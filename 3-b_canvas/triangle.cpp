#include <iostream>
#include "triangle.h"

Triangle::Triangle(int _width, int _height, char _fill)
	: Shape(_width, _height, _fill)
{
	resize(_width, _height);
}

void Triangle::draw()
{
	for (auto& line : drawn_triangle)
		std::cout << line << '\n';
}

double Triangle::area()
{
	// triangle has two same sides (gleichschenklig)
	return (double) get_width() * get_height() / 2.0;
}

void Triangle::resize(int new_width, int new_height)
{
	Shape::resize(new_width, new_height);
	drawn_triangle.clear();

	if (new_width <= 0 || new_height <= 0)
		return;

	drawn_triangle.resize(new_height, std::string(new_width, ' '));
	
	bool is_width_even = (get_width() % 2) == 0;

	for (int y = 0; y < get_height(); y++)
	{
		double ratio = ((double)y + 1.0) / get_height();
		int row_width = (int)(get_width() * ratio);

		// for better symmetry, make sure size always changes by 2
		if (row_width % 2 == 1 && is_width_even)
			row_width++;
		else if (row_width % 2 == 0 && !is_width_even)
			row_width++;


		// amount of whitespace before we can print the fill
		int start = (get_width() - row_width) / 2;
		int end = row_width + start;

		while (start <= end)
		{
			drawn_triangle[y][start] = get_fill();
			start++;
		}
	}
}

char Triangle::char_at(Point p)
{
	if (p.x == 0 || p.x >= get_width())
		return 0;
	if (p.y < 0 || p.y >= get_height())
		return 0;
	return drawn_triangle[p.y][p.x];
}
