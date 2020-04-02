#include "amUuid_T.h"

template <class T>
void amUuid_T<T>::insert(amUuid uuid, T * template_class_ptr)
{
	this->dictionary_.insert_or_assign(uuid, template_class_ptr);
}

template <class T>
T * amUuid_T<T>::find(amUuid uuid)
{

	if (this->dictionary_.count(uuid) == 0)
	{
		return nullptr;
	}
	else
	{
		return this->dictionary_.at(uuid);
	}
}