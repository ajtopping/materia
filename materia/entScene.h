#pragma once

/// <summary>
/// A simple container for a list of amUuid objects
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include <unordered_set>

#include "amUuid.h"
#include "entComposition.hpp"

class entScene
{
public:
	void addCompositionEntity(entComposition);
	amUuid findEntityUuid(entComposition);
	std::unordered_set<amUuid, amUuidHasher> getEntityUuidSet();
	
	amUuid get_uuid() { return uuid_; }
private:
	std::unordered_set<amUuid,amUuidHasher> setAmUuid_;

	amUuid uuid_ = amUuid();
};