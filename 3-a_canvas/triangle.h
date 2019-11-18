#pragma once
#include "shape.h"

class Triangle :
	public Shape
{
public:
	Triangle(int _width, int _height, char _fill = '#');

	void draw();
	double area();
};

