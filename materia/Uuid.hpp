#pragma once

#include "am_UuidRegistry.h"

namespace util
{
	namespace uuid
	{
		namespace // Anonymous
		{
			template <class T>
			am_UuidRegistry<T> uuid_registry_;
		}

		template <class T>
		void Register(T t_val)
		{
			// Register &t_val to a brand new amUuid
		}

		template <class T>
		void Unregister(T t_val)
		{
			// Delete entry associated with t_val uuid and Nil that uuid
		}
	}
}