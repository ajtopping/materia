#pragma once

#include <rpc.h>

struct amUuidEquator
{
	bool operator()(UUID & lh, UUID & rh) const
	{
		return UuidEqual(&lh, &rh, nullptr);
	}
};