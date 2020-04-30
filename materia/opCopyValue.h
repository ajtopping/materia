#pragma once

#include "amUuid.h"
#include "am_S_UniqueUuidAssociator.h"

class opCopyValue
{
public:
	amUuid copy_to_this_uuid;
	amUuid copy_from_this_uuid;

	bool eval();
private:
	bool copy_to_uuid_exists_();
	bool copy_from_uuid_exists_();
	bool types_match_();
};