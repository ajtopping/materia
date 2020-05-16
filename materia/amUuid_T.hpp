#pragma once

#include <unordered_map>

#include "amUuid.h"

template <class T>
class amUuid_T
{
public:
	void insert(amUuid, T*);
	T * find(amUuid);
	size_t remove(amUuid);
private:
	std::unordered_map<amUuid, T*, amUuidHasher> dictionary_;
};

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

template <class T>
size_t amUuid_T<T>::remove(amUuid uuid)
{
	return this->dictionary_.erase(uuid);
}