#include <iostream>
#include <string>
#include <algorithm>
#include "line.h"

Line::Line(int _width, int _height, char _fill, bool _downward)
	: Shape(_width, _height, _fill), downward(_downward)
{
	resize(_width, _height);
}

void Line::draw()
{
	for (auto& line : drawn_line)
		std::cout << line << '\n';
}

double Line::area()
{
	return 0.0;
}

void Line::resize(int new_width, int new_height)
{
	// update width / height parameters
	Shape::resize(new_width, new_height);

	// reset vector
	drawn_line.clear();

	if (get_height() <= 0 || get_width() <= 0)
		return;

	// matrix for our string to be printed
	drawn_line.resize(get_height(), std::string(get_width(), ' '));

	// Using the Bresenham algorithm to draw a line
	// note that there may be simpler ways to achieve the same goal
	// https://de.wikipedia.org/wiki/Bresenham-Algorithmus

	// x / y coordinates to increment
	int x = 0;
	int y, endy;
	if (downward)
	{
		// startpoint is top left, end at the bottom right
		y = 0;
		endy = get_height() - 1;
	}
	else
	{
		// startpoint is bottom left, end at top right
		y = get_height() - 1;
		endy = 0;
	}

	// distances from start-point to end-point
	int dx = get_width() - 1;
	int dy = -(get_height() - 1);

	// error values e_xy
	// each time a threshold is surpassed, x / y coordinate gets adjusted
	int err = dx + dy, e2;

	while (1)
	{
		// write pixel
		drawn_line[y][x] = get_fill();

		// did we reach the end point?
		if (x == get_width() - 1 && y == endy)
			break;

		// check error threshold
		e2 = 2 * err;
		if (e2 > dy)
		{
			err += dy;
			x++;
		} /* e_xy+e_x > 0 */

		if (e2 < dx)
		{
			err += dx;
			y += (downward ? 1 : -1);
		} /* e_xy+e_y < 0 */
	}
}

char Line::char_at(Point p)
{
	if (p.x < 0 || p.x >= get_width())
		return 0;
	if (p.y < 0 || p.y >= get_height())
		return 0;
	return drawn_line[p.y][p.x];
}
