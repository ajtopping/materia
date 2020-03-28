
#include "ssRectangle.h"


ssRectangle::ssRectangle(float x1, float y1, float x2, float y2)
{
	set_bounds(x1, y1, x2, y2);
}

bool operator== (const ssRectangle& lhs, const ssRectangle& rhs)
{
	return lhs.uuid_ == rhs.uuid_;
}

void ssRectangle::set_bounds(float x1, float y1, float x2, float y2)
{
	if (x1 < x2)
	{
		left_ = x1;
		right_ = x2;
	}
	else
	{
		left_ = x2;
		right_ = x1;
	}

	if (y1 < y2)
	{
		bottom_ = y1;
		top_ = y2;
	}
	else
	{
		bottom_ = y2;
		top_ = y1;
	}
}