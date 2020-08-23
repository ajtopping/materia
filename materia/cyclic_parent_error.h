#pragma once

#include <stdexcept>

/// <summary>
/// A run_time error that should be thrown when trying to create an A->B->A parent cycle in a ParentRegistrar
/// </summary>
/// <remarks>
/// 
/// </remarks>
class cyclic_parent_error :
	public std::runtime_error
{
	std::string _Message;

public:
	typedef std::runtime_error _Mybase;

	explicit cyclic_parent_error(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{
	}

	explicit cyclic_parent_error(const char *_Message)
		: _Mybase(_Message)
	{
	}
};