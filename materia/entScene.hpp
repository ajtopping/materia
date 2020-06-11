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
	
private:
	std::unordered_set<amUuid,amUuidHasher> setAmUuid;
};

void entScene::addCompositionEntity(entComposition composition)
{
	setAmUuid.insert(composition.get_uuid());
}

amUuid entScene::findEntityUuid(entComposition composition)
{
	if (setAmUuid.count(composition.get_uuid()) == 0)
	{
		return amUuid(0);
	}

	auto iter = setAmUuid.find(composition.get_uuid());

	return *iter;
}

std::unordered_set<amUuid, amUuidHasher> entScene::getEntityUuidSet()
{
	return setAmUuid;
}