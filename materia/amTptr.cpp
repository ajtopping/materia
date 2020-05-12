#include "amTptr.h"

template amTptr<float>::amTptr();
template amTptr<float>::amTptr(float * new_ptr);
template void amTptr<float>::set_ptr(float * new_ptr);
template float * amTptr<float>::get_ptr();

template amTptr<int>::amTptr();
template amTptr<int>::amTptr(int * new_ptr);
template void amTptr<int>::set_ptr(int * new_ptr);
template int * amTptr<int>::get_ptr();