#pragma once

/// <summary>
/// A pointer to an unknown type (with UUID)
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amUuid.h"

enum AMPTRTYPE
{
	AM_PTR_VOID,
	AM_PTR_FLOAT,
	AM_PTR_INT,
};

class amPtr
{
public:
	//amPtr() {};
	amPtr(void * new_ptr, AMPTRTYPE new_ptrtype) : ptr_(new_ptr), ptrtype_(new_ptrtype) {};

	AMPTRTYPE get_ptrtype() { return ptrtype_; }

	//void set_ptr(void * new_ptr) { ptr_ = new_ptr; }
	//void * get_ptr() { return ptr_; }
private:
	void * ptr_ = nullptr;
	AMPTRTYPE ptrtype_ = AM_PTR_VOID;
	amUuid uuid_ = amUuid();
};