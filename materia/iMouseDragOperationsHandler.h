#pragma once

/// <summary>
/// A container for an ssRectangleSpace (and etc) that is used for translating mouse coordinates into an opOperation
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "am_S_UniqueUuidAssociator.h"
#include "amUuid_T.hpp"
#include "ssRectangleSpace.h"
#include "opMouseDragTransform.h"

class iMouseDragOperationsHandler
{
public:
	iMouseDragOperationsHandler(ssRectangleSpace & r_ref, amUuid_T<opMouseDragTransform *> & o_ref) : rectangleSpace_ref_(r_ref), operations_ref_(o_ref) {};
	opMouseDragTransform * find_operation_from_screen_coordinates(int, int);
private:
	ssRectangleSpace & rectangleSpace_ref_;
	amUuid_T<opMouseDragTransform *> & operations_ref_;
};