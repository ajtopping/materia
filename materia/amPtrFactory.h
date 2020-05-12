#pragma once

/// <summary>
/// Static class that constructs amPtr objects with correct type
/// </summary>
/// <remarks>
/// In a just world, most of this would be macro'd or templated
/// </remarks>

#include "amPtr.h"

class amPtrFactory
{
	amPtrFactory() = delete;
	amPtrFactory(amPtrFactory const&) = delete;
	void operator=(amPtrFactory const&) = delete;

	amPtr make( float * );
	amPtr make( int * );

};