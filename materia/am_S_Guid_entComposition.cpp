#include "am_S_Guid_entComposition.h"

am_S_Guid_entComposition * am_S_Guid_entComposition::instance_ = nullptr;

am_S_Guid_entComposition * am_S_Guid_entComposition::get_instance()
{
	if (!instance_)
	{
		instance_ = new am_S_Guid_entComposition();
	}
	return instance_;
}

void am_S_Guid_entComposition::insert(entComposition & ent)
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