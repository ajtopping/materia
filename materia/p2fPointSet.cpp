#include "p2fPointSet.h"

size_t p2fPointSet::get_num_points()
{
	if (datablock_ == nullptr)
		return 0;

	size_t bytes_per_point = type_.get_total_bytes_for_all_components();

	// Trailing bytes that do not add up to an entire point are ignored
	return datablock_->get_size_in_bytes() / bytes_per_point;
}