#pragma once

#include "am_S_Uuid_T.hpp"

namespace util
{
	template <class T>
	T GetComponent( amUuid composition_uuid )
	{
		return am_S_Uuid_T<T>::find(composition_uuid);
	}

	template <class T>
	bool HasComponent(amUuid composition_uuid)
	{
		return am_S_Uuid_T<T>::has(composition_uuid);
	}
}