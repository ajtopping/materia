#include "RandomGenerator.h"

dDataBlock RandomGenerator::Floats(size_t num_to_generate, float range_inclusive_min, float range_inclusive_max)
{
	auto arr_floats = std::make_unique<float[]>(num_to_generate);

	for (size_t i = 0; i < num_to_generate; i++)
	{
		arr_floats[i] = glm::linearRand(range_inclusive_min, range_inclusive_max);
	}

	size_t size_in_bytes = num_to_generate * sizeof(float);
	dDataType type;
	dDataBlock data(arr_floats, size_in_bytes);
	data.type = type;

	return data;
}