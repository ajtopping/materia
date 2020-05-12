#include "amPtrFactory.h"

amPtr amPtrFactory::make(float * ptr)
{
	return amPtr(ptr, AM_PTR_FLOAT);
}

amPtr amPtrFactory::make(int * ptr)
{
	return amPtr(ptr, AM_PTR_INT);
}