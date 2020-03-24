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

void am_S_UniqueUuidAssociator::insert(UUID uuid1, UUID uuid2)
{
	this->dictionary_.insert_or_assign(uuid1, uuid2);
}

UUID am_S_UniqueUuidAssociator::find(UUID uuid)
{
	try
	{
		return this->dictionary_.at(uuid);
	}
	catch (std::exception e)
	{
		fprintf(stdout, "Could not find UUID that maps to UUID '%lX%lX%lX%lX' in the dictionary! Returning nullptr...\n", uuid.Data1, uuid.Data2, uuid.Data3, uuid.Data4);
		return NULL;
	}
}