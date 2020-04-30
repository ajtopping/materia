
#include "opCopyValue.h"

bool opCopyValue::eval()
{

	return false;
}

bool opCopyValue::copy_to_uuid_exists_()
{
	return !am_S_UniqueUuidAssociator::get_instance()->find(copy_to_this_uuid).isNil();
}

bool opCopyValue::copy_from_uuid_exists_()
{
	return !am_S_UniqueUuidAssociator::get_instance()->find(copy_from_this_uuid).isNil();
}

bool opCopyValue::types_match_()
{
	amUuid copy_to_owner_uuid = am_S_UniqueUuidAssociator::get_instance()->find(copy_to_this_uuid);
	amUuid copy_from_owner_uuid = am_S_UniqueUuidAssociator::get_instance()->find(copy_from_this_uuid);

	return false;
}