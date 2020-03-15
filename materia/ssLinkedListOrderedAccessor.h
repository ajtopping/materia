#pragma once

#include "ssLinkedList.h"

template <class T>
class ssLinkedListOrderedAccessor
{
public:
	ssLinkedListOrderedAccessor(bool(*parameters_are_in_correct_order)(T, T));
	int Insert(ssDirectedNode<T>);
	bool Delete(int index);
	ssDirectedNode * find_first_node_greater_than(T);
private:
	ssLinkedList linkedlist_ = ssLinkedList();
	bool(*f)(T, T) compare_fptr_;
};

template <class T>
ssLinkedListOrderedAccessor<T>::ssLinkedListOrderedAccessor(bool(*parameters_are_in_correct_order)(T, T))
{
	compare_fptr_ = parameters_are_in_correct_order;
}

template <class T>
int ssLinkedListOrderedAccessor<T>::Insert(ssDirectedNode<T> new_node)
{
	int index = 0;
	int length = linkedlist_.get_length();
	ssDriectedNode<T> curr_node = linkedlist_.root;
	while (curr_node.next != nullptr)
	{
		if (compare_fptr(new_node.data, curr_node.data))
		{
			// replace curr with new, make curr the .next of new
		}
	}
	return 0;
}