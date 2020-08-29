#pragma once

#include <stdexcept>

/// <summary>
/// A run_time error that is thrown if an object can not be added to a registry
/// </summary>
/// <remarks>
/// 
/// </remarks>
class invalid_registration_error :
	public std::runtime_error
{
	std::string _Message;

public:
	typedef std::runtime_error _Mybase;

	explicit invalid_registration_error(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{	// construct from message string
	}

	explicit invalid_registration_error(const char *_Message)
		: _Mybase(_Message)
	{	// construct from message string
	}
};