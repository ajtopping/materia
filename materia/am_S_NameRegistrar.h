#pragma once

/// <summary>
/// A singleton that uniquely pairs a Name (std::string) and an amUuid.
/// </summary>
/// <remarks>
/// Renaming and replacing the value of an already existing entry must be done explicitly with provided methods.
/// </remarks>

#include <unordered_map>

#include "amUuid.h"
#include "invalid_name_insert_error.h"

class am_S_NameRegistrar
{
public:
	am_S_NameRegistrar(am_S_NameRegistrar const&) = delete;
	void operator=(am_S_NameRegistrar const&) = delete;

	static void rename_or_insert(std::string, amUuid);
	static void insert(std::string, amUuid);

	static amUuid find_uuid(std::string);
	static std::string find_name(amUuid);

	static bool has_uuid(amUuid);
	static bool has_name(std::string);
	
	static void remove(std::string);
	static void remove(amUuid);
private:
	am_S_NameRegistrar() {};
	static am_S_NameRegistrar * get_instance_();

	void static insert_or_update_entry_(std::string, amUuid);
	void static remove_entry_(std::string, amUuid);

	bool static is_valid_name(std::string);
	bool static is_valid_uuid(amUuid);

	std::unordered_map<std::string, amUuid> dict_string_to_uuid_;
	std::unordered_map<amUuid, std::string, amUuidHasher> dict_uuid_to_string_;

	static am_S_NameRegistrar * instance_;
};