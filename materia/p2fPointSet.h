#pragma once

#include "dDataBlock.h"
#include "dDataType.h"

#define X_SIZE_BYTES sizeof(float)
#define Y_SIZE_BYTES sizeof(float)

class p2fPointSet
{
public:
	p2fPointSet() : type_({ X_SIZE_BYTES, Y_SIZE_BYTES }) {};
	p2fPointSet(dDataBlock * datablock) : type_({ 4 }) { datablock_ = datablock; };

	void set_datablock(dDataBlock * datablock) { datablock_ = datablock; };

	size_t get_num_points();
private:
	dDataType type_;
	dDataBlock * datablock_ = nullptr;

};