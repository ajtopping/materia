#include "dDataType.h"

dDataType::dDataType(std::vector<unsigned int> v)
{
	spec = v;

	for (auto &i : spec)
	{
		total_bytes_for_all_components_ += i;
	}
}

size_t dDataType::get_total_bytes_for_all_components()
{
	return total_bytes_for_all_components_;
}