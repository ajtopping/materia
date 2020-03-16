
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

}