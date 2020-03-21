#pragma once

#include "ssDirectedNode.h"

template <class T = int>
class ssLinkedList
{
public:
	ssDirectedNode<T> * root_ptr;
	void set_length(int new_length) { length_ = new_length; }
	int get_length() { return length_; }

private:
	int length_ = 0;
};