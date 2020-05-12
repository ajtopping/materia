#pragma once

/// <summary>
/// A singleton that uniquely maps one UUID to an amTptr
/// </summary>
/// <remarks>
/// This will become obsolete very quickly.
/// </remarks>

#include <unordered_map>
#include "amUuid.h"
#include "amTptr.h"

class am_S_amTptr
{
public:
	am_S_amTptr(am_S_amTptr const&) = delete;
	void operator=(am_S_amTptr const&) = delete;

	static am_S_amTptr * get_instance();
	void insert(amTptr);
	amTptr find(amUuid);
private:
	am_S_amTptr() {};

	std::unordered_map<amUuid, amTptr, amUuidHasher> dictionary_;

	static am_S_amTptr * instance_;
};