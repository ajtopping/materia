#include "p2dEdgeSet.h"

void p2dEdgeSet::set_verts_datablock(dDataBlock * data_ref)
{
	verts_ = data_ref;
}

void p2dEdgeSet::set_indexed_edges_datablock(dDataBlock * data_ref)
{
	indexed_edges_ = data_ref;
}

size_t p2dEdgeSet::get_num_of_verts()
{
	if (verts_ == nullptr)
		return 0;

	return verts_->get_size_in_bytes();
}