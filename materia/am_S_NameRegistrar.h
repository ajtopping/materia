#pragma once

/// <summary>
/// A singleton wrapper for am_NameRegistrar
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include <unordered_map>

#include "am_NameRegistrar.h"

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

	am_NameRegistrar name_registrar_;

	static am_S_NameRegistrar * instance_;
};