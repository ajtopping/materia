#pragma once

#include "am_ParentRegistry.h"

namespace util
{
	namespace parent
	{
		namespace // Anonymous
		{
			am_ParentRegistry parent_registry_;
		}

		void RegisterRelationship(amUuid child_uuid, amUuid parent_uuid)
		{
			parent_registry_.make_parent(child_uuid, parent_uuid);
		}

		bool HasParent(amUuid child_uuid)
		{
			return parent_registry_.has_parent(child_uuid);
		}

		void ClearParent(amUuid child_uuid)
		{
			parent_registry_.clear_parent(child_uuid);
		}

		void ClearChild(amUuid child_uuid, amUuid parent_uuid)
		{
			parent_registry_.clear_child(child_uuid, parent_uuid);
		}
	}
}