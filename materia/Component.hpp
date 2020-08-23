#pragma once

#include "am_S_Uuid_T.hpp"
#include "am_NameRegistrar.h"

namespace util
{
	namespace component
	{
		template <class T>
		T GetComponent(amUuid composition_uuid)
		{
			return am_S_Uuid_T<T>::find(composition_uuid);
		}

		template <class T>
		bool HasComponent(amUuid composition_uuid)
		{
			return am_S_Uuid_T<T>::has(composition_uuid);
		}

		template <class T>
		void AttachComponent(amUuid composition_uuid, T t_val)
		{
			return am_S_Uuid_T<T>::insert(composition_uuid, t_val);
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