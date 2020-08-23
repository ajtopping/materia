#include "am_NameRegistrar.h"

void am_NameRegistrar::rename_or_insert(std::string name, amUuid uuid)
{
	insert_or_update_entry_(name, uuid);
}

void am_NameRegistrar::insert(std::string name, amUuid uuid)
{
	std::string error_message = "am_NameRegistrar::insert :";
	bool has_error = false;

	if (has_name(name))
	{
		error_message += " An entry with the name '" + name + "' already exists.";
		has_error = true;
	}

	if (has_uuid(uuid))
	{
		std::string name = find_name(uuid);
		error_message += " A uuid already corresponds to the name '" + name + "'";
		has_error = true;
	}

	if (has_error)
	{
		error_message += "\n";
		throw invalid_name_insert_error(error_message);

		return;
	}

	insert_or_update_entry_(name, uuid);
}

amUuid am_NameRegistrar::find_uuid(std::string key)
{
	if (dict_string_to_uuid_.count(key) == 0)
	{
		return amUuid(0);
	}
	else
	{
		return dict_string_to_uuid_.at(key);
	}
}

std::string am_NameRegistrar::find_name(amUuid key)
{
	if (dict_uuid_to_string_.count(key) == 0)
	{
		return "";
	}
	else
	{
		return dict_uuid_to_string_.at(key);
	}
}

bool am_NameRegistrar::has_uuid(amUuid key)
{
	if (dict_uuid_to_string_.count(key) == 0)
	{
		return false;
	}

	return true;
}

bool am_NameRegistrar::has_name(std::string key)
{
	if (dict_string_to_uuid_.count(key) == 0)
	{
		return false;
	}

	return true;
}

void am_NameRegistrar::remove(std::string name)
{
	amUuid uuid = find_uuid(name);
	remove_entry_(name, uuid);
}

void am_NameRegistrar::remove(amUuid uuid)
{
	std::string name = find_name(uuid);
	remove_entry_(name, uuid);
}

void am_NameRegistrar::insert_or_update_entry_(std::string name, amUuid uuid)
{
	dict_string_to_uuid_.insert_or_assign(name, uuid);
	dict_uuid_to_string_.insert_or_assign(uuid, name);
}

void am_NameRegistrar::remove_entry_(std::string name, amUuid uuid)
{
	dict_string_to_uuid_.erase(name);
	dict_uuid_to_string_.erase(uuid);
}

bool am_NameRegistrar::is_valid_name(std::string name)
{
	return name.empty();
}

bool am_NameRegistrar::is_valid_uuid(amUuid uuid)
{
	return uuid.isNil();
}