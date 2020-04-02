
#include "opSetValue.h"

template <typename T>
bool opSetValue<T>::eval()
{
	if (value_ptr == nullptr || setter_ptr == nullptr)
	{
		return false;
	}

	*value_ptr = *setter_ptr;

	return true;
}