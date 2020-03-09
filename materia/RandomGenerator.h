#pragma once

#include "gtc/random.hpp"

#include "dDataBlock.h"

/// <summary>
/// Generates a block of random data with the given parameters
/// </summary>
/// <remarks>
/// Used for creating dDataBlock objects
/// </remarks>
class RandomGenerator
{
public:
	static dDataBlock Floats( size_t num_to_generate, float range_inclusive_max = 1.0f, float range_inclusive_min = 0.0f);
private:
	RandomGenerator() {}
};