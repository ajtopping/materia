#pragma once

#include "am_S_Uuid_T.hpp"
#include "am_Uuid_T.hpp"
#include "am_NameRegistrar.h"
#include "no_valid_component_error.h"
#include "no_valid_entity_error.h"

namespace util
{
	namespace component
	{
		namespace //Anonymous
		{
			template <class T>
			am_Uuid_T<T> uuid_to_t_;

			template <class T>
			am_Uuid_T<T> owner_to_component_;
		}

		template <class T>
		T GetComponent(amUuid composition_uuid)
		{
			//return am_S_Uuid_T<T>::find(composition_uuid);
			component_uuid = owner_to_component_<T>.find(composition_uuid);
			return uuid_to_t_<T>.find(component_uuid);
		}

		template <class T>
		bool HasComponent(amUuid composition_uuid)
		{
			//return am_S_Uuid_T<T>::has(composition_uuid);
			return owner_to_component_<T>.has(composition_uuid);
		}

		template <class T>
		void AttachComponent(amUuid composition_uuid, T t_val)
		{
			return am_S_Uuid_T<T>::insert(composition_uuid, t_val);
		}

		template <class T>
		void AttachComponent(amUuid owner_uuid, amUuid component_uuid)
		{
			//return am_S_Uuid_T<T>::insert(composition_uuid, t_val);

			bool has_error = false;
			std::string error_msg = "util::component::AttachComponent : ";

			if (!uuid_to_t_<T>.has(component_uuid))
			{
				has_error = true;
				error_msg += " component_uuid does not correspond to a component of type " + typeid(T).name() + "/n";
			}

			if (has_error)
			{
				throw no_valid_component_error(error_msg);
			}

			owner_to_component_<T>.insert(owner_uuid, component_uuid);

		}

		/*
		template <class T>
		T NewComponent(amUuid composition_uuid)
		{
			broken
			return am_S_Uuid_T<T>::insert(composition_uuid, t_val);
		}
		*/
	}
}