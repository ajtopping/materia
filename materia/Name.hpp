#include "amUuid.h"
#include "am_NameRegistrar.h"

namespace util
{
	namespace name
	{
		namespace // Anonymous
		{
			am_NameRegistrar name_registrar_;
		}

		void RegisterName(std::string name, amUuid uuid)
		{
			name_registrar_.insert(name, uuid);
		}

		void RegisterOrRename(std::string name, amUuid uuid)
		{
			name_registrar_.rename_or_insert(name, uuid);
		}

		std::string FindName(amUuid uuid)
		{
			return name_registrar_.find_name(uuid);
		}

		amUuid FindUuid(std::string name)
		{
			return name_registrar_.find_uuid(name);
		}

		bool HasName(std::string name)
		{
			return name_registrar_.has_name(name);
		}

		bool HasUuid(amUuid uuid)
		{
			return name_registrar_.has_uuid(uuid);
		}

		void Unregister(std::string name)
		{
			name_registrar_.remove(name);
		}

		void Unregister(amUuid uuid)
		{
			name_registrar_.remove(uuid);
		}
	}
}