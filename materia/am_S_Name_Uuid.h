#pragma once

/// <summary>
/// A singleton that uniquely maps a Name (std::string) to amUuid.
/// </summary>
/// <remarks>
/// Renaming and replacing the value of an already existing entry must be done explicitly with provided methods.
/// </remarks>

#include <unordered_map>

#include "amUuid.h"
#include "invalid_name_insert_error.h"

class am_S_Name_Uuid
{
public:
	am_S_Name_Uuid(am_S_Name_Uuid const&) = delete;
	void operator=(am_S_Name_Uuid const&) = delete;

	static void rename_or_insert(std::string, amUuid);
	static void insert(std::string, amUuid);
	static amUuid find( std::string );
	static bool has(std::string);
	static size_t remove(std::string);
private:
	am_S_Name_Uuid() {};
	static am_S_Name_Uuid * get_instance();

	std::unordered_map<std::string, amUuid> dictionary_;

	static am_S_Name_Uuid * instance_;
};