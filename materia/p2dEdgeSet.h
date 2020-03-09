#pragma once

#include "dDataBlock.h"

class p2dEdgeSet
{
public:
	void set_verts_datablock(dDataBlock *);
	void set_indexed_edges_datablock(dDataBlock *);

	size_t get_num_of_verts();
	size_t get_num_of_indexed_edges();
private:
	dDataBlock * verts_ = nullptr;
	dDataBlock * indexed_edges_ = nullptr;
};