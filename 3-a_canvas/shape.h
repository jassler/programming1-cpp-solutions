#pragma once
class Shape
{
private:
	int width;
	int height;

	char fill;

public:
	Shape(int _width, int _height, char _fill = '#');

	virtual void draw() = 0;
	virtual double area() = 0;

	virtual void resize(int new_width, int new_height);

	int get_width();
	int get_height();
	char get_fill();
};

