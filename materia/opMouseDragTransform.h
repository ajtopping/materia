#pragma once

/// <summary>
/// OPERATION: Applies XY translation to a transform based on a MouseValues reference
/// </summary>
/// <remarks>
/// Uses the current mouse_hover and mouse_down values along with the transform's initial coordinates to calculate the translation
/// </remarks>

#include "opOperation.h"

#include "i_S_MouseValues.h"
#include "mTransform.h"

class opMouseDragTransform : public opOperation
{
public:
	opMouseDragTransform(i_S_MouseValues & ms_ref, mTransform & t_ref) : mousevalues_ref_(ms_ref), transform_ref_(t_ref), initial_x_(t_ref.posX()), initial_y_(t_ref.posY()) {};
	void operate();
protected:
	i_S_MouseValues & mousevalues_ref_;
	mTransform & transform_ref_;
	float initial_x_;
	float initial_y_;
};