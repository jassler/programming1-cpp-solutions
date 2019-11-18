#pragma once
#include <vector>
#include <tuple>
#include "shape.h"
#include "point.h"

class Canvas
{
private:
	std::vector<std::tuple<Shape*, Point>> shapes;
	
	int width, height;

public:
	Canvas(int _width, int _height);

	void add_shape(Shape* s, Point p);
	void clear();

	void draw();
};

