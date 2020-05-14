#pragma once

/// <summary>
/// 
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "mTransform.h"

class opTranslateTransformXY
{
	opTranslateTransformXY(float x, float y, mTransform &);
	explicit opTranslateTransformXY(mTransform &, mTransform);
};