#include "gTreeNode.h"

void gTreeNode::set_parent(gNode * new_parent)
{
	parent_ = new_parent;
}

gNode * gTreeNode::get_parent()
{
	return parent_;
}

void gTreeNode::clear_parent()
{
	parent_ = nullptr;
}