#pragma once

/// <summary>
/// Base class for a pointer to a primitive type (with UUID)
/// </summary>
/// <remarks>
/// Default type is void*
/// </remarks>

#include "amUuid.h"

class amPtrPrimitive
{
public:
	amPtrPrimitive() = delete;
	amPtrPrimitive(amPtrPrimitive const&) = delete;
	void operator=(amPtrPrimitive const&) = delete;

	virtual void set_ptr(void * new_ptr) { ptr_ = new_ptr; }
	virtual void * get_ptr() { return ptr_; }

	amUuid get_uuid() { return uuid_; }
protected:
	void * ptr_ = nullptr;

	amUuid uuid_ = amUuid();

};