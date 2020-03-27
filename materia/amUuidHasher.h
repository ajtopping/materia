#pragma once

#include <rpc.h>

struct amUuidHasher
{
	size_t operator()(UUID & uuid) const
	{
		return UuidHash(&uuid, nullptr);
	}
};