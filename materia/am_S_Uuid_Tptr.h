#pragma once

/// <summary>
/// A singleton that uniquely maps one UUID to pointer of type T
/// </summary>
/// <remarks>
/// This will become obsolete very quickly.
/// </remarks>

#include <unordered_map>
#include "amUuid.h"

template <class T>
class am_S_Uuid_Tpter
{
public:
	am_S_Uuid_Tpter(am_S_Uuid_Tpter const&) = delete;
	void operator=(am_S_Uuid_Tpter const&) = delete;

	static am_S_Uuid_Tpter * get_instance();
	void insert(amUuid, T*);
	T * find(amUuid);
private:
	am_S_Uuid_Tpter() {};

	std::unordered_map<amUuid, T*, amUuidHasher> dictionary_;

	static am_S_Uuid_Tpter * instance_;
};