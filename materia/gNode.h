#pragma once

#include <vector>

class gNode
{
public:
	gNode() {};

	std::vector<gNode*> get_children() const { return children_; };
private:
	std::vector<gNode*> children_;
};