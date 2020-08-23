#pragma once

#include "am_ParentRegistrar.h"

namespace util
{
	namespace parent
	{
		namespace // Anonymous
		{
			am_ParentRegistrar parent_registrar_;
		}

		void RegisterRelationship(amUuid child_uuid, amUuid parent_uuid)
		{
			parent_registrar_.make_parent(child_uuid, parent_uuid);
		}

		bool HasParent(amUuid child_uuid)
		{
			return parent_registrar_.has_parent(child_uuid);
		}

		void ClearParent(amUuid child_uuid)
		{
			parent_registrar_.clear_parent(child_uuid);
		}

		void ClearChild(amUuid child_uuid, amUuid parent_uuid)
		{
			parent_registrar_.clear_child(child_uuid, parent_uuid);
		}
	}
}