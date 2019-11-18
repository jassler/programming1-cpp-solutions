#pragma once
#include <vector>
#include "shape.h"

class Line :
	public Shape
{
private:
	// if downward, start from the upper left corner and go to the bottom right: \
	// otherwise it starts from the bottom left corner and goes to the top right: /
	bool downward;

	std::vector<std::string> drawn_line;

public:
	Line(int _width, int _height, char _fill = '#', bool _downward = true);

	void draw();
	double area();

	void resize(int new_width, int new_height);
	char char_at(Point p);
};

