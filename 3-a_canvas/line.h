#pragma once
#include "shape.h"
class Line :
	public Shape
{
private:
	// if downward, start from the upper left corner and go to the bottom right: \
	// otherwise it starts from the bottom left corner and goes to the top right: /
	bool downward;

public:
	Line(int _width, int _height, char _fill = '#', bool _downward = true);

	void draw();
	double area();
};

