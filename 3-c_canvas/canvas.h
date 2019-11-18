#pragma once
#include <vector>
#include <tuple>
#include "shape.h"
#include "point.h"

class Canvas
	: public Shape
{
private:
	std::vector<std::tuple<Shape*, Point>> shapes;
	std::vector<std::string> drawing;
	
	void draw_shape_on_canvas(std::tuple<Shape*, Point> s);

public:
	Canvas(int _width, int _height);

	void add_shape(Shape* s, Point p);
	void clear();

	double area();
	char char_at(Point p);
	void resize(int new_width, int new_height);
	void draw();
};

