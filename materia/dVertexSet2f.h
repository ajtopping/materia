#pragma once

#include "dDataBlock.h"

class dVertexSet2f
{
public:
	dVertexSet2f();

private:
	dDataBlock data_;
};

dVertexSet2f::dVertexSet2f()
{
	data_ = dDataBlock();
	data_.type = dDataType({ 4, 4 });
}