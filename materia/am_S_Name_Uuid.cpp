
#include "am_S_Name_Uuid.h"

void am_S_Name_Uuid::rename_or_insert(std::string key, amUuid uuid)
{
	am_S_Name_Uuid::get_instance()->dictionary_.insert_or_assign(key, uuid);
}

void am_S_Name_Uuid::insert(std::string key, amUuid uuid)
{
	if (am_S_Name_Uuid::has(key))
	{
		std::string error_message = "am_S_Name_Uuid::insert : Cannot insert key '" + key + "' because it already exists.\n";
		throw new invalid_name_insert_error(error_message);

		return;
	}

	am_S_Name_Uuid::get_instance()->dictionary_.insert_or_assign(key, uuid);
}

amUuid am_S_Name_Uuid::find(std::string key)
{

	if (am_S_Name_Uuid::get_instance()->dictionary_.count(key) == 0)
	{
		return amUuid(0);
	}
	else
	{
		return am_S_Name_Uuid::get_instance()->dictionary_.at(key);
	}
}

bool am_S_Name_Uuid::has(std::string key)
{

	if (am_S_Name_Uuid::get_instance()->dictionary_.count(key) == 0)
	{
		return false;
	}

	return true;
}

size_t am_S_Name_Uuid::remove(std::string key)
{
	return am_S_Name_Uuid::get_instance()->dictionary_.erase(key);
}