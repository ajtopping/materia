#pragma once

#include <stdexcept>

/// <summary>
/// A run_time error that should be thrown when trying to attach/retrieve a typed component and no component of that type is available
/// </summary>
/// <remarks>
/// 
/// </remarks>
class no_valid_component_error :
	public std::runtime_error
{
	std::string _Message;

public:
	typedef std::runtime_error _Mybase;

	explicit no_valid_component_error(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{	// construct from message string
	}

	explicit no_valid_component_error(const char *_Message)
		: _Mybase(_Message)
	{	// construct from message string
	}
};