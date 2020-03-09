#include "PolygonGenerator.h"

dDataBlock PolygonGenerator::Ngon(size_t number_of_sides)
{
	if (number_of_sides < 3)
	{
		throw new illogical_polygon_parameter_error("Cannot generate an Ngon with fewer than 3 sides.");
	}

	size_t amount_to_generate = number_of_sides * 2;
	auto arr_floats = std::make_unique<float[]>(amount_to_generate);
	float inside_angle = glm::two_pi<float>() / number_of_sides;

	for (size_t i = 0; i < number_of_sides; i++)
	{
		arr_floats[2*i] = glm::sin(inside_angle*i); // X
		arr_floats[2*i+1] = glm::cos(inside_angle*i); // Y
	}

	size_t size_in_bytes = amount_to_generate * sizeof(float);
	dDataType type;
	dDataBlock data(arr_floats, size_in_bytes);
	data.type = type;

	return data;
}