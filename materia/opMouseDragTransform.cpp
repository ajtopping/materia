#include "opMouseDragTransform.h"

void opMouseDragTransform::operate()
{
	float down_x = mousevalues_ref_.mousedown_x;
	float down_y = mousevalues_ref_.mousedown_y;

	float hover_x = mousevalues_ref_.mousehover_x;
	float hover_y = mousevalues_ref_.mousehover_y;

	transform_ref_.posX(initial_x_ + (hover_x - down_x));
	transform_ref_.posY(initial_y_ - (hover_y - down_y));  // Mouse values are relative to upper left corner as (0,0)
}

void opMouseDragTransform::reinitialize()
{
	initial_x_ = transform_ref_.posX();
	initial_y_ = transform_ref_.posY();
}