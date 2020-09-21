#pragma once

#include "amUuid.h"
//#include "am_UuidRegistry.h"
//#include "Uuid.hpp"

class amUuidRegistryTicket
{
public:
	amUuidRegistryTicket() { uuid_ = amUuid(0); }
	amUuidRegistryTicket(amUuid uuid) { uuid_ = uuid; }
	amUuidRegistryTicket(amUuidRegistryTicket const& ref) : uuid_(ref.uuid_) {}; // is_registered = false // prevents erroneous deconstruction side effects
	void operator=(amUuidRegistryTicket const& ref) {
		uuid_ = ref.uuid_;
		is_registered_ = false;
	}

	~amUuidRegistryTicket()
	{ 
		if (is_registered_)
		{
			//util::uuid::Unregister(uuid_);
		}
	}

	friend class am_UuidRegistry;

	bool isNil() { return uuid_.isNil(); }
private:
	amUuid uuid_ = amUuid(0);
	bool is_registered_ = false;
};