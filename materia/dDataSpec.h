#pragma once

/* Describes how a contiguous chunk of memory should be partitioned into 
units of equal length
*/
struct dDataSpec
{
	int bytes_per_unit = 1;
};