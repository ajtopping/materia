#pragma once

/// <summary>
/// Uniquely pairs an amUuid to an amUuid signifying a parent-child relationship
/// </summary>
/// <remarks>
/// Always prevents inserts with nil amUuid (amUuid(0))
/// </remarks>

#include <unordered_map>

#include "am_Uuid_T.hpp"
#include "am_HasUuid.h"

//template <class T>
class am_UuidRegistry
{
public:
	void make_parent(amUuid, amUuid);

	amUuid find_parent(amUuid);

	bool has_parent(amUuid);

	void clear_parent(amUuid);
	void clear_child(amUuid child_uuid, amUuid parent_uuid);
	void clear_children(amUuid);
private:
	void make_entry_(amUuid, amUuid);
	void remove_entry_(amUuid);
	bool has_entry_(amUuid, amUuid);

	//am_Uuid_T<T> uuid_to_ref_map_;
	std::unordered_map<amUuid, am_HasUuid&, amUuidHasher> uuid_to_ref_map_;
};