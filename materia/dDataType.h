#pragma once

#include <vector>

#include "dDataSpec.h"

/*
Describes how bytes are partitioned for a data type.
Ex.
A pixel with color might be described as
[ x ][ y ][  r  ][  g  ][  b  ][is_visible]
[int][int][float][float][float][   bool   ]
[ 4 ][ 4 ][  4  ][  4  ][  4  ][     1    ]
*/
struct dDataType
{
	dDataType(std::vector<unsigned int> v = { 1 });
	std::vector<unsigned int> spec;

	size_t get_total_bytes_for_all_components();

private:
	size_t total_bytes_for_all_components_ = 0;
};

