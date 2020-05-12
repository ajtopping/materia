#pragma once

/// <summary>
/// Static class that manages type conversions
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amPtr.h"

class amTypeConverter
{
	amTypeConverter() = delete;
	amTypeConverter(amTypeConverter const&) = delete;
	void operator=(amTypeConverter const&) = delete;

	void find_converter(AMPTRTYPE to_this_type, AMPTRTYPE from_this_type);

};