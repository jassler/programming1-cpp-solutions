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
	double area();
	char char_at(Point p);

	void resize(int new_width, int new_height);

	char get_border();
};

