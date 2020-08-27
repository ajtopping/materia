#pragma once

/// <summary>
/// Interface for guaranteeing subclasses have a uuid
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amUuid.h"
#include "am_UuidRegistry.h"

class am_HasUuid
{
public:
	am_HasUuid() = delete;
	am_HasUuid(am_HasUuid const&) = delete;
	void operator=(am_HasUuid const&) = delete;

	amUuid get_uuid() { return uuid_; }
protected:
	amUuid uuid_ = amUuid(0);

	friend am_UuidRegistry;
private:
};