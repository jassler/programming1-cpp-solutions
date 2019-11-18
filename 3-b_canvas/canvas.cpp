#include <iostream>
#include <algorithm>
#include <string>
#include "canvas.h"

Canvas::Canvas(int _width, int _height)
	: width(_width), height(_height)
{
}

void Canvas::add_shape(Shape* s, Point p)
{
	shapes.push_back(std::make_tuple(s, p));
}

void Canvas::clear()
{
	// remove all elements from shapes
	shapes.clear();
}

void Canvas::draw()
{
	std::vector<std::string> drawing(height, std::string(width, ' '));

	// tuple structured binding, c++17 required
	// alternatively tuple elements can be extracted as follows:
	// auto& shape = std::get<0>(t);
	// auto& point = std::get<1>(t);
	for (auto& [shape, point] : shapes)
	{
		// make sure coordinates of point starts positive and doesn't exceed width / height limit
		int y_start = std::max(0, point.y);
		int y_end = std::min(point.y + shape->get_height(), height);

		int x_start = std::max(0, point.x);
		int x_end = std::min(point.x + shape->get_width(), width);

		// char at certain location inside the shape
		// special case if starting coordinate is negative, then we have to start somewhere inside the shape
		Point point_in_shape(0, 0);
		if (point.y < 0)
			point_in_shape.y = -point.y;

		int px_start = 0;
		if (point.x < 0)
			px_start = -point.x;

		for (int y = point.y; y < point.y + shape->get_height() && y < height; y++)
		{
			point_in_shape.x = 0;
			for (int x = point.x; x < point.x + shape->get_width() && x < width; x++)
			{
				char c = shape->char_at(point_in_shape);
				if (c != 0 && c != ' ')
					drawing[y][x] = c;
				point_in_shape.x++;
			}
			point_in_shape.y++;
		}
	}

	for (auto& line : drawing)
		std::cout << line << '\n';
}
