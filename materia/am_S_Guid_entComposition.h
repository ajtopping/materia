#pragma once

/// <summary>
/// Describes order and size of each data chunk in the raw bits of a dDataBlock
/// </summary>
/// <remarks>
/// The order is implied by the index in the vector
/// </remarks>

#include <unordered_map>
#include <string>
#include <rpc.h>

#include "entComposition.h"

class am_S_Guid_entComposition
{
public:
	am_S_Guid_entComposition(am_S_Guid_entComposition const&) = delete;
	void operator=(am_S_Guid_entComposition const&) = delete;
	
	static am_S_Guid_entComposition * get_instance();
	void insert(entComposition &);
	entComposition * find(UUID);
private:
	am_S_Guid_entComposition() {};

	std::unordered_map<UUID, entComposition *> dictionary_;

	static am_S_Guid_entComposition * instance_;
};

