
#include "am_S_NameRegistrar.h"

void am_S_NameRegistrar::rename_or_insert(std::string name, amUuid uuid)
{
	am_S_NameRegistrar::insert_or_update_entry_(name, uuid);
}

void am_S_NameRegistrar::insert(std::string name, amUuid uuid)
{
	std::string error_message = "";
	bool has_error = false;

	if (am_S_NameRegistrar::has_name(name))
	{
		error_message += "am_S_Name_Uuid::insert : An entry with the name '" + name + "' already exists.\n";
		has_error = true;
	}

	if (am_S_NameRegistrar::has_uuid(uuid))
	{
		std::string name = am_S_NameRegistrar::find_name(uuid);
		error_message += "am_S_Name_Uuid::insert : A uuid already corresponds to the name '" + name + "'\n";
		has_error = true;
	}

	if (has_error)
	{
		throw new invalid_name_insert_error(error_message);

		return;
	}

	am_S_NameRegistrar::insert_or_update_entry_(name, uuid);
}

amUuid am_S_NameRegistrar::find_uuid(std::string key)
{
	if (am_S_NameRegistrar::get_instance_()->dict_string_to_uuid_.count(key) == 0)
	{
		return amUuid(0);
	}
	else
	{
		return am_S_NameRegistrar::get_instance_()->dict_string_to_uuid_.at(key);
	}
}

std::string am_S_NameRegistrar::find_name(amUuid key)
{
	if (am_S_NameRegistrar::get_instance_()->dict_uuid_to_string_.count(key) == 0)
	{
		return "";
	}
	else
	{
		return am_S_NameRegistrar::get_instance_()->dict_uuid_to_string_.at(key);
	}
}

bool am_S_NameRegistrar::has_uuid(amUuid key)
{
	if (am_S_NameRegistrar::get_instance_()->dict_uuid_to_string_.count(key) == 0)
	{
		return false;
	}

	return true;
}

bool am_S_NameRegistrar::has_name(std::string key)
{
	if (am_S_NameRegistrar::get_instance_()->dict_string_to_uuid_.count(key) == 0)
	{
		return false;
	}

	return true;
}

void am_S_NameRegistrar::remove(std::string name)
{
	amUuid uuid = am_S_NameRegistrar::find_uuid(name);
	am_S_NameRegistrar::remove_entry_(name, uuid);
}

void am_S_NameRegistrar::remove(amUuid uuid)
{
	std::string name = am_S_NameRegistrar::find_name(uuid);
	am_S_NameRegistrar::remove_entry_(name, uuid);
}

am_S_NameRegistrar * am_S_NameRegistrar::get_instance_()
{
	if (!am_S_NameRegistrar::instance_)
	{
		am_S_NameRegistrar::instance_ = new am_S_NameRegistrar();
	}
	return instance_;
}

void am_S_NameRegistrar::insert_or_update_entry_(std::string name, amUuid uuid)
{
	am_S_NameRegistrar::get_instance_()->dict_string_to_uuid_.insert_or_assign(name, uuid);
	am_S_NameRegistrar::get_instance_()->dict_uuid_to_string_.insert_or_assign(uuid, name);
}

void am_S_NameRegistrar::remove_entry_(std::string name, amUuid uuid)
{
	am_S_NameRegistrar::get_instance_()->dict_string_to_uuid_.erase(name);
	am_S_NameRegistrar::get_instance_()->dict_uuid_to_string_.erase(uuid);
}

bool am_S_NameRegistrar::is_valid_name(std::string name)
{
	return name.empty();
}

bool am_S_NameRegistrar::is_valid_uuid(amUuid uuid)
{
	return uuid.isNil();
}