#pragma once

#include <rpc.h>

class entComposition
{
public:
	entComposition() { UuidCreate(&uuid_); }
	UUID get_uuid() { return uuid_; }
private:
	UUID uuid_;
};