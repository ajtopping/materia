#include "am_S_amTptr.h"

am_S_amTptr * am_S_amTptr::instance_ = nullptr;

am_S_amTptr * am_S_amTptr::get_instance()
{
	if (!instance_)
	{
		instance_ = new am_S_amTptr();
	}
	return instance_;
}

void am_S_amTptr::insert(amTptr Tptr)
{
	this->dictionary_.insert_or_assign(ent.get_uuid(), &ent);
}

entComposition * am_S_Guid_entComposition::find(amUuid uuid)
{
	try
	{
		return this->dictionary_.at(uuid);
	}
	catch (std::exception e)
	{
		fprintf(stdout, "Could not find entComposition with UUID '%llX' in the dictionary! Returning nullptr...\n", uuid.get_data());
		return nullptr;
	}
}