#pragma once

/// <summary>
/// A map that associates a Uuids. Uses templates to hint at the relationship between the Uuids.
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include <unordered_map>

#include "amUuid.h"

template <class T>
class am_Uuid_Uuid
{
public:
	void insert(amUuid, amUuid);
	amUuid find(amUuid);
	bool has(amUuid);
	size_t remove(amUuid);
private:
	std::unordered_map<amUuid, amUuid, amUuidHasher> dictionary_;
};

template <class T>
void am_Uuid_Uuid<T>::insert(amUuid key, amUuid value)
{
	this->dictionary_.insert_or_assign(key, value);
}

template <class T>
amUuid am_Uuid_Uuid<T>::find(amUuid key)
{

	if (this->dictionary_.count(key) == 0)
	{
		return amUuid(0);
	}
	else
	{
		return this->dictionary_.at(key);
	}
}

template <class T>
bool am_Uuid_Uuid<T>::has(amUuid key)
{

	if (this->dictionary_.count(key) == 0)
	{
		return false;
	}

	return true;
}

template <class T>
size_t am_Uuid_Uuid<T>::remove(amUuid key)
{
	return this->dictionary_.erase(key);
}