
#include "ssRectangle.h"

int ssRectangle::guid_ = 0;

ssRectangle::ssRectangle(float x1, float y1, float x2, float y2)
{
	id_ = ssRectangle::NEXT_GUID_();

	set_bounds(x1, y1, x2, y2);
}

bool operator== (ssRectangle & lhs, ssRectangle & rhs)
{
	return lhs.id_ == rhs.id_;
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

int ssRectangle::NEXT_GUID_()
{
	return ssRectangle::guid_++;
}