#pragma once

#include "am_S_Uuid_T.hpp"
#include "am_Uuid_T.hpp"
#include "am_Uuid_Uuid.hpp"
#include "Uuid.hpp"
//#include "am_NameRegistry.h"
#include "no_valid_component_error.h"
#include "no_valid_entity_error.h"

namespace util
{
	namespace component
	{
		namespace //Anonymous
		{
			template <class T>
			am_Uuid_Uuid<T> owner_to_component_;
		}

		template <class T>
		bool HasComponent(amUuid owner_uuid)
		{
			amUuid component_uuid = owner_to_component_<T>.find(owner_uuid);
			return util::uuid::HasRegisteredType<T>(component_uuid);
		}

		template <class T>
		T & GetComponent(amUuid owner_uuid)
		{
			amUuid component_uuid = owner_to_component_<T>.find(owner_uuid);
			std::string error_msg = "util::component::GetComponent : ";

			if (component_uuid.isNil())
			{
				error_msg += "owner_uuid has no corresponding component_uuid for component type " + std::string(typeid(T).name()) + " / n";
				throw no_valid_component_error(error_msg);
			}

			if (!HasComponent<T>(owner_uuid))
			{
				error_msg += "the corresponding component_uuid has not been registered with util::uuid registry of type " + std::string(typeid(T).name()) + " / n";
				throw no_valid_component_error(error_msg);
			}

			return util::uuid::GetRegisteredType<T>(component_uuid);
		}

		template <class T>
		void AttachComponent(amUuid owner_uuid, amUuid component_uuid)
		{
			bool has_error = false;
			std::string error_msg = "util::component::AttachComponent : ";

			if (!util::uuid::HasRegisteredType<T>(component_uuid))
			{
				has_error = true;
				error_msg += " component_uuid does not correspond to a component of type " + std::string(typeid(T).name()) + "/n";
			}

			if (has_error)
			{
				throw no_valid_component_error(error_msg);
			}

			owner_to_component_<T>.insert(owner_uuid, component_uuid);

		}

		template <class T>
		void RegisterAndAttachComponent(amUuid owner_uuid, am_HasUuidRegistryTicket & ref)
		{
			if (!util::uuid::IsRegistered(ref))
			{
				util::uuid::Register(ref);
			}

			AttachComponent<T>(owner_uuid, ref.get_uuid());
		}

		template <class T>
		size_t DetachComponent(amUuid owner_uuid)
		{
			return owner_to_component_<T>.remove(owner_uuid);
		}
	}
}