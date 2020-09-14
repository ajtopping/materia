#include "am_UuidRegistry.h"

amUuid am_UuidRegistry::Register(am_HasUuidRegistryTicket & ref)
{
	if ( !ref.get_uuid().isNil())
	{
		throw invalid_registration_error("am_UuidRegistry::Register : cannot register object because its uuid is Nil (cannot register a Nil uuid).\n");
	}

	if ( !ref.ticket_is_nil())
	{
		throw invalid_registration_error("am_UuidRegistry::Register : cannot register object because its registry ticket is not Nil (it has already been registered).\n");
	}

	uuid_to_ref_map_.insert_or_assign(ref.get_uuid(), ref);
	ref.ticket_.uuid_ = ref.get_uuid();
	ref.ticket_.is_registered_ = true;

	return ref.get_uuid();
}

void am_UuidRegistry::Unregister(am_HasUuidRegistryTicket & ref)
{
	uuid_to_ref_map_.erase(ref.get_uuid());
	ref.ticket_.is_registered_ = false;
}

void am_UuidRegistry::Unregister(amUuid uuid)
{
	if (!has(uuid))
	{
		return;
	}

	am_HasUuidRegistryTicket & ref = uuid_to_ref_map_.at(uuid);
	uuid_to_ref_map_.erase(uuid);
	ref.ticket_.is_registered_ = false;
}

bool am_UuidRegistry::has(amUuid uuid)
{
	return uuid_to_ref_map_.count(uuid) != 0;
}

am_HasUuidRegistryTicket & am_UuidRegistry::get(amUuid uuid)
{
	return uuid_to_ref_map_.at(uuid);
}