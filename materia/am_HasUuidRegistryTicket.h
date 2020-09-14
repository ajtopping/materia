#pragma once

/// <summary>
/// Interface for guaranteeing subclasses have a uuid and registry ticket
/// </summary>
/// <remarks>
/// 
/// </remarks>

//#include "amUuid.h"
#include "amUuidRegistryTicket.h"
//#include "am_UuidRegistry.h"

class am_HasUuidRegistryTicket
{
public:
	am_HasUuidRegistryTicket() = delete;
	am_HasUuidRegistryTicket(am_HasUuidRegistryTicket const&) = delete;
	void operator=(am_HasUuidRegistryTicket const&) = delete;

	friend class am_UuidRegistry;

	amUuid get_uuid() { return uuid_; }
	bool ticket_is_nil() { return ticket_.isNil(); }

	virtual void make_dynamic_cast_happy() = 0;
protected:
	
private:
	amUuid uuid_;
	amUuidRegistryTicket ticket_;
};