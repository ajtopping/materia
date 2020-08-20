
#include "am_S_NameRegistrar.h"

am_S_NameRegistrar * am_S_NameRegistrar::instance_ = nullptr;

void am_S_NameRegistrar::rename_or_insert(std::string name, amUuid uuid)
{
	am_S_NameRegistrar::get_instance_()->name_registrar_.rename_or_insert(name, uuid);
}

void am_S_NameRegistrar::insert(std::string name, amUuid uuid)
{
	am_S_NameRegistrar::get_instance_()->name_registrar_.insert(name, uuid);
}

amUuid am_S_NameRegistrar::find_uuid(std::string key)
{
	return am_S_NameRegistrar::get_instance_()->name_registrar_.find_uuid(key);
}

std::string am_S_NameRegistrar::find_name(amUuid key)
{
	return am_S_NameRegistrar::get_instance_()->name_registrar_.find_name(key);
}

bool am_S_NameRegistrar::has_uuid(amUuid key)
{
	return am_S_NameRegistrar::get_instance_()->name_registrar_.has_uuid(key);
}

bool am_S_NameRegistrar::has_name(std::string key)
{
	return am_S_NameRegistrar::get_instance_()->name_registrar_.has_name(key);
}

void am_S_NameRegistrar::remove(std::string name)
{
	am_S_NameRegistrar::get_instance_()->name_registrar_.remove(name);
}

void am_S_NameRegistrar::remove(amUuid uuid)
{
	am_S_NameRegistrar::get_instance_()->name_registrar_.remove(uuid);
}

am_S_NameRegistrar * am_S_NameRegistrar::get_instance_()
{
	if (!am_S_NameRegistrar::instance_)
	{
		am_S_NameRegistrar::instance_ = new am_S_NameRegistrar();
	}
	return instance_;
}