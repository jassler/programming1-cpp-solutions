#include <iostream>
#include "canvas.h"
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include "line.h"

int main()
{
	Canvas drawing(40, 21);
	
	Rectangle background(40, 21, (char) 254u, '.');
	Ellipse circle(15, 11);
	Ellipse corner_quarter_circle(6, 6, 'O');
	Triangle triangle(15, 8, '^');
	Line line(38, 1, '-');

	drawing.add_shape(&background, Point(0, 0));

	for (int y = 2; y <= 18; y += 2)
		drawing.add_shape(&line, Point(1, y));

	drawing.add_shape(&circle, Point(2, 2));
	drawing.add_shape(&circle, Point(22, 2));

	drawing.add_shape(&corner_quarter_circle, Point(-3, -3));
	drawing.add_shape(&corner_quarter_circle, Point(-3, 18));
	drawing.add_shape(&corner_quarter_circle, Point(36, -3));
	drawing.add_shape(&corner_quarter_circle, Point(36, 18));

	drawing.add_shape(&triangle, Point(12, 10));


	Canvas big_drawing(79, 21);
	big_drawing.add_shape(&drawing, Point(0, 0));
	big_drawing.add_shape(&drawing, Point(39, 0));
	
	big_drawing.draw();
}
