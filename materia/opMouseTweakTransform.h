#pragma once

/// <summary>
/// OPERATION: Applies XY translation to a transform from the mouse_tweak values of a MouseValues reference
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "opOperation.h"

#include "i_S_MouseValues.h"
#include "mTransform.h"

class opMouseTweakTransform : public opOperation
{
public:
	opMouseTweakTransform(i_S_MouseValues & ms_ref, mTransform & t_ref) : mousevalues_ref_(ms_ref), transform_ref_(t_ref) {};
	void operate();
protected:
	i_S_MouseValues & mousevalues_ref_;
	mTransform & transform_ref_;
};