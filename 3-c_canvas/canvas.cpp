#include <iostream>
#include <algorithm>
#include <string>
#include "canvas.h"

void Canvas::draw_shape_on_canvas(std::tuple<Shape*, Point> t)
{
	// structured binding, c++17 required
	// alternatively tuple elements can be extracted as follows:
	// auto& shape = std::get<0>(t);
	// auto& point = std::get<1>(t);
	auto& [shape, point] = t;

	// make sure coordinates of point starts positive and doesn't exceed width / height limit
	int y_start = std::max(0, point.y);
	int y_end = std::min(point.y + shape->get_height(), get_height());

	int x_start = std::max(0, point.x);
	int x_end = std::min(point.x + shape->get_width(), get_width());

	// char at certain location inside the shape
	// special case if starting coordinate is negative, then we have to start somewhere inside the shape
	Point point_in_shape(0, 0);
	if (point.y < 0)
		point_in_shape.y = -point.y;
	
	int px_start = 0;
	if (point.x < 0)
		px_start = -point.x;
	
	// start drawing!
	for (int y = y_start; y < y_end; y++)
	{
		point_in_shape.x = px_start;
		for (int x = x_start; x < x_end; x++)
		{
			char c = shape->char_at(point_in_shape);

			// assuming that 0 and whitespace are the characters returned if there's no block there
			if (c != 0 && c != ' ')
				drawing[y][x] = c;
			point_in_shape.x++;
		}
		point_in_shape.y++;
	}
}

Canvas::Canvas(int _width, int _height)
	: Shape(_width, _height)
{
	resize(_width, _height);
}

void Canvas::add_shape(Shape* s, Point p)
{
	auto t = std::make_tuple(s, p);
	shapes.push_back(t);
	draw_shape_on_canvas(t);
}

void Canvas::clear()
{
	// remove all elements from shapes
	shapes.clear();
	
	// reset drawing
	for (auto& line : drawing)
		std::fill(line.begin(), line.end(), ' ');
}

double Canvas::area()
{
	return (double) get_width() * get_height();
}

char Canvas::char_at(Point p)
{
	if (p.x < 0 || p.x >= get_width())
		return 0;
	if (p.y < 0 || p.y >= get_height())
		return 0;
	return drawing[p.y][p.x];
}

void Canvas::resize(int new_width, int new_height)
{
	// clear everything
	Shape::resize(new_width, new_height);
	drawing.clear();

	if (new_width <= 0 || new_height <= 0)
		return;

	// redraw all the shapes
	drawing.resize(new_height, std::string(new_width, ' '));
	for (auto s : shapes)
		draw_shape_on_canvas(s);
}

void Canvas::draw()
{
	for (auto& line : drawing)
		std::cout << line << '\n';
}
