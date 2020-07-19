#include "entScene.h"

void entScene::addCompositionEntity(entComposition composition)
{
	setAmUuid_.insert(composition.get_uuid());
}

amUuid entScene::findEntityUuid(entComposition composition)
{
	if (setAmUuid_.count(composition.get_uuid()) == 0)
	{
		return amUuid(0);
	}

	auto iter = setAmUuid_.find(composition.get_uuid());

	return *iter;
}

std::unordered_set<amUuid, amUuidHasher> entScene::getEntityUuidSet()
{
	return setAmUuid_;
}