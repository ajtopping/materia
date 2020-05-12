#pragma once

/// <summary>
/// Static base class for all type conversions
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amPtr.h"

class amTypeConversion
{
	amTypeConversion() = delete;
	amTypeConversion(amTypeConversion const&) = delete;
	void operator=(amTypeConversion const&) = delete;

	void find_converter(AMPTRTYPE to_this_type, AMPTRTYPE from_this_type);

};