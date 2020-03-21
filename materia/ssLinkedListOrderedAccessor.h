#pragma once

#include "ssLinkedList.h"

template <class T>
class ssLinkedListOrderedAccessor
{
public:
	ssLinkedListOrderedAccessor(bool(*parameters_are_in_correct_order)(T, T));
	int Insert(T);
	bool Delete(int index);
	ssDirectedNode * find_first_node_greater_than(T);
private:
	ssLinkedList<T> linkedlist_ = ssLinkedList();
	bool(*f)(T, T) compare_fptr_;
};

template <class T>
ssLinkedListOrderedAccessor<T>::ssLinkedListOrderedAccessor(bool(*parameters_are_in_correct_order)(T, T))
{
	compare_fptr_ = parameters_are_in_correct_order;
}

template <class T>
int ssLinkedListOrderedAccessor<T>::Insert(T new_node_data)
{
	int index = 0;
	int length = linkedlist_.get_length();
	ssDirectedNode<T> * new_node_ptr = new ssDirectedNode<T>(new_node_data);
	ssDirectedNode<T> ** curr_node_ptr_ptr = &linkedlist_.root_ptr;

	if (curr_node_ptr_ptr* == nullptr)
	{
		linkedlist_.root_ptr = new_node_ptr;
		return;
	}

	if (compare_fptr_(new_node.data, curr_node_ptr->data))
	{
		new_node.next = curr_node;
		linkedlist_.root = new_node;
	}

	while (curr_node_ptr->next != nullptr && index < length)
	{
		if (compare_fptr_(new_node_ptr->data, curr_node_ptr->data))
		{
			// replace curr with new, make curr the .next of new
			new_node_ptr->next = curr_node_ptr;
		}
	}
	return 0;
}