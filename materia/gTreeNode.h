#pragma once

#include "gNode.h"

/* Node that guarantees a single parent
*/

class gTreeNode : public gNode
{
public:
	gTreeNode() {};
	gTreeNode(gNode * parent) { set_parent(parent); };

	void set_parent(gNode * parent);
	gNode * get_parent();
	void clear_parent();
private:
	gNode * parent_ = nullptr;
};