#pragma once

#include "dDataType.h"

#include <memory>

/* Memory container that takes ownership of a void *
A dDataBlock is partitioned into chunks of memory of
the same "type". The underlying type of the data block
is described by a dDataType. Think of a data block as
an array of a type described by a type.

Ex:
dVertexSet2f
[ vertex ][ vertex ] ...
A set of vertexes
[ x ][ y ][ x ][ y ] ...
composed of 2 units per vertex
[ 4 ][ 4 ][ 4 ][ 4 ] ...
where each unit is 4 bytes in length
*/
struct dDataBlock
{
public:
	dDataBlock(std::unique_ptr<float[]> & uptr_ref, size_t size) : data_(std::move(uptr_ref)), type(), size_in_bytes_(size) {}
	//dDataBlock(dDataBlock&) = default;
	dDataType type;
	//void set_data( const std::unique_ptr<float[]> & , size_t );
	
	float * get_data_pointer() { return data_.get();  }
	size_t get_size_in_bytes() { return size_in_bytes_; }
private:
	std::unique_ptr<float[]> data_;
	size_t size_in_bytes_;
};



