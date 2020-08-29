#include "am_UuidRegistry.h"

amUuid am_UuidRegistry::Register(am_HasUuid & ref)
{
	if ( !ref.get_uuid().isNil())
	{
		throw invalid_registration_error("am_UuidRegistry::Register : cannot register object because its uuid is not Nil (it has already been registered).\n");
	}

	amUuid new_uuid;
	uuid_to_ref_map_.insert_or_assign(new_uuid, ref);
	ref.uuid_ = new_uuid;

	return new_uuid;
}

void am_UuidRegistry::Unregister(am_HasUuid & ref)
{
	uuid_to_ref_map_.erase(ref.get_uuid());
	ref.uuid_ = amUuid(0);
}