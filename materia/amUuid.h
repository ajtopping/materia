#pragma once

#include <chrono>

#include "Clock.h"

class amUuid
{
public:
	bool operator==(const amUuid & rh) const
	{
		return data_ == rh.get_data();
	}

	amUuid()
	{
		auto now = std::chrono::high_resolution_clock::now();
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch());

		data_ = microseconds.count();
	}

	amUuid(long long uuid)
	{
		data_ = uuid;
	}

	long long get_data() const { return data_; }

	bool isNil() const { return data_ == 0; }
private:
	long long data_;

};

class amUuidHasher
{
public:
	size_t operator()(const amUuid & rh) const
	{
		return rh.get_data();
	}
};