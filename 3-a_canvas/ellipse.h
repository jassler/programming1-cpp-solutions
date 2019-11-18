#pragma once
#include "shape.h"

class Ellipse :
	public Shape
{
public:
	Ellipse(int _width, int _height, char _fill = '#');

	void draw();
	double area();
};


