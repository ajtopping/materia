
#include "am_ParentRegistry.h"

void am_ParentRegistry::make_parent(amUuid child_uuid, amUuid parent_uuid)
{
	std::string error_message = "am_ParentRegistrar::make_parent :";
	bool has_error = false;

	if (child_uuid.isNil())
	{
		error_message += " child_uuid cannot be nil.";
		has_error = true;
	}

	if (parent_uuid.isNil())
	{
		error_message += " parent_uuid cannot be nil.";
		has_error = true;
	}

	if (has_error)
	{
		error_message += "\n";
		throw std::runtime_error(error_message);

		return;
	}

	make_entry_(child_uuid, parent_uuid);
}

amUuid am_ParentRegistry::find_parent(amUuid child_uuid)
{
	if (child_to_parent_map_.count(child_uuid) == 0)
	{
		return amUuid(0);
	}
	else
	{
		return child_to_parent_map_.at(child_uuid);
	}
}

bool am_ParentRegistry::has_parent(amUuid child_uuid)
{
	if (child_to_parent_map_.count(child_uuid) == 0)
	{
		return false;
	}

	return true;
}

void am_ParentRegistry::clear_parent(amUuid child_uuid)
{
	remove_entry_(child_uuid);
}

void am_ParentRegistry::clear_child(amUuid child_uuid, amUuid parent_uuid)
{
	amUuid found_parent_uuid = find_parent(child_uuid);
	if (parent_uuid == child_uuid)
	{
		remove_entry_(child_uuid);
	}
}

void am_ParentRegistry::clear_children(amUuid parent_uuid)
{
	throw std::logic_error("am_ParentRegistrar::clear_children() : this function has not been implemented yet.\n");
}

void am_ParentRegistry::make_entry_(amUuid child_uuid, amUuid parent_uuid)
{
	child_to_parent_map_.insert_or_assign(child_uuid, parent_uuid);
}

void am_ParentRegistry::remove_entry_(amUuid child_uuid)
{
	child_to_parent_map_.erase(child_uuid);
}

bool am_ParentRegistry::has_entry_(amUuid child_uuid, amUuid parent_uuid)
{

	amUuid found_parent_uuid = find_parent(child_uuid);
	return parent_uuid == found_parent_uuid;
}