#include "amUuid.h"
#include "am_NameRegistry.h"

namespace util
{
	namespace name
	{
		namespace // Anonymous
		{
			am_NameRegistry name_registry_;
		}

		void RegisterName(std::string name, amUuid uuid)
		{
			name_registry_.insert(name, uuid);
		}

		void RegisterOrRename(std::string name, amUuid uuid)
		{
			name_registry_.rename_or_insert(name, uuid);
		}

		std::string FindName(amUuid uuid)
		{
			return name_registry_.find_name(uuid);
		}

		amUuid FindUuid(std::string name)
		{
			return name_registry_.find_uuid(name);
		}

		bool HasName(std::string name)
		{
			return name_registry_.has_name(name);
		}

		bool HasUuid(amUuid uuid)
		{
			return name_registry_.has_uuid(uuid);
		}

		void Unregister(std::string name)
		{
			name_registry_.remove(name);
		}

		void Unregister(amUuid uuid)
		{
			name_registry_.remove(uuid);
		}
	}
}