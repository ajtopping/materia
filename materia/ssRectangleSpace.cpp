
#include "ssRectangleSpace.h"

void ssRectangleSpace::insert_rectangle(ssRectangle new_rectangle)
{
	rectangles_.push_front(new_rectangle);
}

void ssRectangleSpace::remove_rectangle(ssRectangle rectangle)
{
	rectangles_.remove(rectangle);
}

std::forward_list<ssRectangle> ssRectangleSpace::find_rectangles_containing_point(float x, float y)
{
	std::forward_list<ssRectangle> found_rectangles;
	for (auto it = rectangles_.begin(); it != rectangles_.end(); it++)
	{
		if (ssRectangleSpace::rectangle_contains_point(*it, x, y))
		{
			found_rectangles.push_front(*it);
		}
	}

	return found_rectangles;
}

bool ssRectangleSpace::rectangle_contains_point(ssRectangle rectangle, float x, float y)
{
	return rectangle.get_world_left() < x && rectangle.get_world_right() > x && rectangle.get_world_bottom() < y && rectangle.get_world_top() > y;
}