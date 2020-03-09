#pragma once

#include <glm.hpp>
#include <gtc/constants.hpp>

#include "illogical_polygon_parameter_error.h"
#include "dDataBlock.h"

/// <summary>
/// Generates a datablock of vertexes for a given unit-sized polygon
/// </summary>
/// <remarks>
/// Used for creating dDataBlock objects
/// </remarks>
class PolygonGenerator
{
public:
	static dDataBlock Ngon(size_t number_of_sides);
private:
	PolygonGenerator() {}
};