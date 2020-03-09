#pragma once

#include <stdexcept>

/// <summary>
/// A logic_error that should be thrown when trying to generate polygons with impossible traits
/// </summary>
/// <remarks>
/// Ex. Ngon with less than 3 sides
/// </remarks>
class illogical_polygon_parameter_error :
	public std::logic_error
{
	std::string _Message;

public:
	typedef std::logic_error _Mybase;

	explicit illogical_polygon_parameter_error(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{	// construct from message string
	}

	explicit illogical_polygon_parameter_error(const char *_Message)
		: _Mybase(_Message)
	{	// construct from message string
	}
};