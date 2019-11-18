#pragma once
#include "shape.h"
class Rectangle :
	public Shape
{
private:
	char border;
	bool is_border(int x, int y);

public:
	Rectangle(int _width, int _height, char _border = '#', char _fill = ' ');

	void draw();
	char get_border();
	double area();
};

