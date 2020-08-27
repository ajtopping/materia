#pragma once

/// <summary>
/// Uniquely pairs an amUuid to an amUuid signifying a parent-child relationship
/// </summary>
/// <remarks>
/// Always prevents inserts with nil amUuid (amUuid(0))
/// </remarks>

#include <unordered_map>

#include "amUuid.h"
#include "cyclic_parent_error.h"

class am_ParentRegistry
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

	std::unordered_map<amUuid, amUuid, amUuidHasher> child_to_parent_map_;
};