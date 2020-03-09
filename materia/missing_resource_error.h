#pragma once

#include <stdexcept>

class missing_resource_error
	: public std::runtime_error {
	std::string _Message;

public:
	typedef std::runtime_error _Mybase;

	explicit missing_resource_error(const std::string& _Message)
		: _Mybase(_Message.c_str())
	{	// construct from message string
	}

	explicit missing_resource_error(const char *_Message)
		: _Mybase(_Message)
	{	// construct from message string
	}
};