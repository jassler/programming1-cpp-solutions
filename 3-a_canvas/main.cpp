#include <iostream>
#include <thread>
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include "line.h"


template<class SHAPE_CLASS, class ... ARGS>
void animate_object(long long sleep_duration_milliseconds, ARGS ... arguments_passed_to_shape)
{
	static_assert(std::is_base_of<Shape, SHAPE_CLASS>::value, "Class passed to template function has to inherit from Shape");

	auto sleep_duration = std::chrono::milliseconds(sleep_duration_milliseconds);
	int width = 1;
	int height = 1;

	int width_add = 1;
	int height_add = 0;

	auto animated_shape = new SHAPE_CLASS(width, height, arguments_passed_to_shape...);

	while (height > 0)
	{

		// draw
		system("cls");
		animated_shape->draw();

		// wait before paint again
		std::this_thread::sleep_for(sleep_duration);
		
		// make shape grow / shrink
		width += width_add;
		height += height_add;

		// check if it's reached max limit
		// if so, change direction the shape is growing / shrinking
		if (width > 10 || width < 1)
		{
			width -= width_add;
			height_add = width_add;
			width_add = 0;
		}
		else if (height > 10)
		{
			height--;
			height_add = 0;
			width_add = -1;
		}

		// resize shape
		animated_shape->resize(width, height);
	}

	delete animated_shape;
}

int main()
{
	animate_object<Rectangle>(50);
	animate_object<Ellipse>(50, 'O');
	animate_object<Line>(50, '^', false);
	animate_object<Triangle>(50);
}
