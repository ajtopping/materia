#include "opMouseTweakTransform.h"

void opMouseTweakTransform::operate()
{
	float tweak_x = mousevalues_ref_.mousetweak_x;
	float tweak_y = mousevalues_ref_.mousetweak_y;

	float transform_x = transform_ref_.posX();
	float transform_y = transform_ref_.posY();

	transform_ref_.posX( transform_x + tweak_x );
	transform_ref_.posY( transform_y + tweak_y );
}