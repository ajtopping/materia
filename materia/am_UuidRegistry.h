#pragma once

/// <summary>
/// Maps amUuid to an am_HasUuid sub-class reference.
/// </summary>
/// <remarks>
/// This registry assigns a new uuid to the object being registered, so
/// the object must have a nil uuid, otherwise an error is thrown
/// </remarks>

#include <unordered_map>

#include "am_Uuid_T.hpp"
#include "am_HasUuid.h"

#include "invalid_registration_error.h"

//template <class T>
class am_UuidRegistry
{
public:
	amUuid Register(am_HasUuid &);
	void Unregister(am_HasUuid &);
private:
	//am_Uuid_T<T> uuid_to_ref_map_;
	std::unordered_map<amUuid, am_HasUuid&, amUuidHasher> uuid_to_ref_map_;
};