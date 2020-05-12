#pragma once

/// <summary>
/// Represents a rectangle used for detecting mouse clicks
/// </summary>
/// <remarks>
/// The rectangle is internally represented by a width, a height, and a transform,
/// but access is also available as bounds that are calculated by these values
/// </remarks>

#include "amUuid.h"
#include "mTransform.h"

class ssRectangle
{
public:
	ssRectangle(float width, float height);
	ssRectangle(float x1, float y1, float x2, float y2);

	friend bool operator== (const ssRectangle& lhs, const ssRectangle& rhs);

	void set_bounds(float, float, float, float);
	void set_dimensions(float, float);
	void set_position(float, float);

	float get_left() { return transform_.posX(); }
	float get_right() { return transform_.posX() + width_; }
	float get_top() { return transform_.posY() + height_; }
	float get_bottom() { return transform_.posY(); }

	amUuid get_uuid() { return uuid_; }
private:
	float width_ = 1.0f;
	float height_ = 1.0f;

	mTransform transform_;

	amUuid uuid_ = amUuid();
};