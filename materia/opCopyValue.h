#pragma once

#include "amUuid.h"

class opCopyValue
{
public:
	amUuid copy_to_this_uuid;
	amUuid copy_from_this_uuid;

	bool eval();
private:
};