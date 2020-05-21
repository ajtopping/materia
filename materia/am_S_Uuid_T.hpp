#pragma once

/// <summary>
/// A singleton that uniquely maps one UUID to template type T.
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include <unordered_map>
#include "amUuid.h"

template <class T>
class am_S_Uuid_T
{
public:
	am_S_Uuid_T(am_S_Uuid_T const&) = delete;
	void operator=(am_S_Uuid_T const&) = delete;

	static am_S_Uuid_T * get_instance();
	static void insert(amUuid, T);
	static T find(amUuid);
	static size_t remove(amUuid);
private:
	am_S_Uuid_T() {};

	std::unordered_map<amUuid, T, amUuidHasher> dictionary_;

	static am_S_Uuid_T * instance_;
};

template <class T>
am_S_Uuid_T<T> * am_S_Uuid_T<T>::instance_ = nullptr;

template <class T>
am_S_Uuid_T<T> * am_S_Uuid_T<T>::get_instance()
{
	if (!am_S_Uuid_T<T>::instance_)
	{
		am_S_Uuid_T<T>::instance_ = new am_S_Uuid_T<T>();
	}
	return instance_;
}

template <class T>
void am_S_Uuid_T<T>::insert(amUuid uuid, T value)
{
	am_S_Uuid_T<T>::get_instance()->dictionary_.insert_or_assign(uuid, value);
}

template <class T>
T am_S_Uuid_T<T>::find(amUuid uuid)
{

	if (am_S_Uuid_T<T>::get_instance()->dictionary_.count(uuid) == 0)
	{
		return nullptr;
	}
	else
	{
		return am_S_Uuid_T<T>::get_instance()->dictionary_.at(uuid);
	}
}

template <class T>
size_t am_S_Uuid_T<T>::remove(amUuid uuid)
{
	return am_S_Uuid_T<T>::get_instance()->dictionary_.erase(uuid);
}