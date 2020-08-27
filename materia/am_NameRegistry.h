#pragma once

/// <summary>
/// Uniquely pairs a Name (std::string) and an amUuid.
/// </summary>
/// <remarks>
/// Renaming and replacing the value of an already existing entry must be done explicitly with provided methods.
/// </remarks>

#include <unordered_map>

#include "amUuid.h"
#include "invalid_name_insert_error.h"

class am_NameRegistry
{
public:

	void rename_or_insert(std::string, amUuid);
	void insert(std::string, amUuid);

	amUuid find_uuid(std::string);
	std::string find_name(amUuid);

	bool has_uuid(amUuid);
	bool has_name(std::string);

	void remove(std::string);
	void remove(amUuid);
private:

	void insert_or_update_entry_(std::string, amUuid);
	void remove_entry_(std::string, amUuid);

	bool is_valid_name(std::string);
	bool is_valid_uuid(amUuid);

	std::unordered_map<std::string, amUuid> dict_string_to_uuid_;
	std::unordered_map<amUuid, std::string, amUuidHasher> dict_uuid_to_string_;
};