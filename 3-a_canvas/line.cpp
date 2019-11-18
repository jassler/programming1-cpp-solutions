#include <iostream>
#include <algorithm>
#include "line.h"
#include <string>

Line::Line(int _width, int _height, char _fill, bool _downward)
	: Shape(_width, _height, _fill), downward(_downward)
{
}

void Line::draw()
{
	if (get_height() <= 0 || get_width() <= 0)
		return;
	
	// matrix for our string to be printed
	// added get_height at the end to include linebreaks and null-terminator
	int size = get_width() * get_height() + get_height();
	char* result = new char[size];
	std::fill(result, result + size, ' ');
	
	// take care of linebreaks and null-terminator
	for (int y = 0; y < get_height() - 1; y++)
	{
		result[get_width() + y * (get_width() + 1)] = '\n';
	}
	result[size - 1] = '\0';

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
	int dx = get_width()-1;
	int dy = -(get_height()-1);

	// error values e_xy
	// each time a threshold is surpassed, x / y coordinate gets adjusted
	int err = dx + dy, e2;

	while (1)
	{
		if (x + y * (get_width() + 1) >= size)
			throw "TOO BIG! x is " + std::to_string(x) + " and y is " + std::to_string(y) + ", got index " + std::to_string(x + y * (get_width() + 1));
		// write pixel
		result[x + y * (get_width() + 1)] = get_fill();

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

	// print line!
	std::cout << result << '\n';

	// free up space again
	delete[] result;
}

double Line::area()
{
	return 0.0;
}
