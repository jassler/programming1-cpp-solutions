#pragma once
#include <vector>
#include "shape.h"

class Ellipse :
	public Shape
{
private:
	std::vector<std::string> drawn_ellipse;

public:
	Ellipse(int _width, int _height, char _fill = '#');

	void draw();
	double area();

	void resize(int new_width, int new_height);
	char char_at(Point p);
};


