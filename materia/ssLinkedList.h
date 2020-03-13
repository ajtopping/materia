#pragma once

#include "ssDirectedNode.h"

class ssLinkedList
{
public:
	ssDirectedNode<int> root;
	int get_length() { return length_; }

private:
	int length_ = 0;
};