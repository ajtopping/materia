#pragma once

#include "ssRectangle.h"

#include <forward_list>

class ssRectangleSpace
{
public:
	void insert_rectangle(ssRectangle);
	void remove_rectangle(ssRectangle);
	std::forward_list<ssRectangle> find_rectangles_containing_point(float x, float y);
private:
	std::forward_list<ssRectangle> rectangles_;
};