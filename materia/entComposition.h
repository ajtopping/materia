#pragma once

#include "amUuid.h"

class entComposition
{
public:
	amUuid get_uuid() const { return uuid_; }
private:
	amUuid uuid_;
};