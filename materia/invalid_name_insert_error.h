#pragma once

#include <stdexcept>

/// <summary>
/// A run_time error that should be thrown when trying to insert a {name, uuid} entry that already exists in a NameRegistrar
/// </summary>
/// <remarks>
/// 
/// </remarks>
class invalid_name_insert_error :
	public std::runtime_error
{
	std::string _Message;

public:
	typedef std::runtime_error _Mybase;

	explicit invalid_name_insert_error(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{	// construct from message string
	}

	explicit invalid_name_insert_error(const char *_Message)
		: _Mybase(_Message)
	{	// construct from message string
	}
};