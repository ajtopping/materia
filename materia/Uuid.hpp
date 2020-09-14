#pragma once

#include <typeinfo>

#include "am_UuidRegistry.h"
#include "am_HasUuidRegistryTicket.h"

namespace util
{
	namespace uuid
	{
		namespace // Anonymous
		{
			am_UuidRegistry uuid_registry_;
		}
		
		void Register(am_HasUuidRegistryTicket & ref);

		void Unregister(am_HasUuidRegistryTicket & ref);

		void Unregister(amUuid uuid);


		/*
		template <class T>
		bool HasRegisteredType(amUuid uuid)
		{
			try
			{
				am_HasUuidRegistryTicket & ref = uuid_registry_.get(uuid);
			}
			catch (std::out_of_range e)
			{
				std::string error_msg = "util::uuid::HasRegisteredType : out_of_range: the given uuid has not been registered.\n";
				fprintf(stdout, error_msg);
				return false;
			}

			try
			{
				// Does am_HasUuidRegistryTicket need a virtual function?
				dynamic_cast<T&>(ref);
			}
			catch (std::bad_cast e)
			{
				std::string error_msg = "util::uuid::HasRegisteredType : bad_cast: the found reference cannot be cast to the given type.\n";
				fprintf(stdout, error_msg);
				return false;
			}

			return true;
		}

		template <class T>
		T & GetRegisteredType(amUuid uuid)
		{
			if (!HasRegisteredType<T>(uuid))
			{
				throw no_valid_component_error("util::uuid::GetReigsteredType : failed HasRegisteredType check.\n");
			}

			// guaranteed safe?
			return static_cast<T&>(uuid_registry_.get(uuid));
		} */
	}
}