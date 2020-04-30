#pragma once

/// <summary>
/// A pointer to a type T (with UUID)
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amUuid.h"

template <class T>
class amTptr
{
public:
	amTptr();
	amTptr(T * new_ptr) : ptr_(new_ptr);
	void set_ptr(T * new_ptr) { ptr_ = new_ptr; }
	T* get_ptr() { return ptr_; }
private:
	T * ptr_ = nullptr;

	amUuid uuid_ = amUuid();

};