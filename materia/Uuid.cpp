#include "Uuid.hpp"

namespace util
{
	namespace uuid
	{
		void Register(am_HasUuidRegistryTicket & ref)
		{
			uuid_registry_.Register(ref);
		}

		void Unregister(am_HasUuidRegistryTicket & ref)
		{
			uuid_registry_.Unregister(ref);
		}

		void Unregister(amUuid uuid)
		{
			uuid_registry_.Unregister(uuid);
		}

		bool IsRegistered(am_HasUuidRegistryTicket & ref)
		{
			return uuid_registry_.has(ref.get_uuid());
		}
	}
}