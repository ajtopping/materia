#pragma once

#include <rpc.h>

class ssRectangle
{
public:
	ssRectangle(float, float, float, float);

	friend bool operator== (const ssRectangle& lhs, const ssRectangle& rhs);

	void set_bounds(float, float, float, float);

	float get_left() { return left_; }
	float get_right() { return right_; }
	float get_top() { return top_; }
	float get_bottom() { return bottom_; }

	UUID get_uuid() { return uuid_; }
private:
	float left_ = 0.0f;
	float right_ = 1.0f;
	float top_ = 1.0f;
	float bottom_ = 0.0f;

	UUID uuid_;
};