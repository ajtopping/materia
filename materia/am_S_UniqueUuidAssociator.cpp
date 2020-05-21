#include "am_S_UniqueUuidAssociator.h"

am_S_UniqueUuidAssociator * am_S_UniqueUuidAssociator::instance_ = nullptr;

am_S_UniqueUuidAssociator * am_S_UniqueUuidAssociator::get_instance()
{
	if (!instance_)
	{
		instance_ = new am_S_UniqueUuidAssociator();
	}
	return instance_;
}

void am_S_UniqueUuidAssociator::insert(amUuid uuid1, amUuid uuid2)
{
	this->dictionary_.insert_or_assign(uuid1, uuid2);
}

amUuid am_S_UniqueUuidAssociator::find(amUuid uuid)
{

	if (this->dictionary_.count(uuid) == 0)
	{
		return amUuid(0);
	}
	else
	{
		return this->dictionary_.at(uuid);
	}
}

size_t am_S_UniqueUuidAssociator::remove(amUuid uuid)
{
	return this->dictionary_.erase(uuid);
}