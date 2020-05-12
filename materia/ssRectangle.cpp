
#include "ssRectangle.h"

ssRectangle::ssRectangle(float width, float height)
{
	set_bounds(0.0f, 0.0f, width, height);
}

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
	width_ = abs(x1 - x2);
	height_ = abs(y1 - y2);

	if (x1 < x2)
	{
		transform_.posX(x1);
	}
	else
	{
		transform_.posX(x2);
	}

	if (y1 < y2)
	{
		transform_.posY(y1);
	}
	else
	{
		transform_.posY(y2);
	}
}

void ssRectangle::set_dimensions(float width, float height)
{
	width_ = width;
	height_ = height;
}

void ssRectangle::set_position(float x1, float y1)
{
	transform_.posX(x1);
	transform_.posY(y1);

}