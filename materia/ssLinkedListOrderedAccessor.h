#pragma once

#include "ssLinkedList.h"

template <class T>

class ssLinkedListOrderedAccessor
{
public:
	ssLinkedListOrderedAccessor(bool(*parameters_are_in_correct_order)(T, T))
	int Insert<T>(ssDirectedNode<T>);
	bool Delete(int index);
	ssDirectedNode * find_first_node_greater_than(T);
private:
	ssLinkedList linkedlist_ = ssLinkedList();
	bool(*f)(T, T) compare_fptr_;
};