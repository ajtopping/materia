#pragma once

#include <chrono>

class Clock
{
public:
	Clock();
	void tick();

	float get_seconds_duration_of_last_tick();
	float get_seconds_duration_since_start();
	std::chrono::microseconds get_microseconds_duration_of_last_tick() { return microseconds_duration_of_last_tick_; }
	std::chrono::microseconds get_microseconds_since_start() { return microseconds_since_start_; }
private:
	std::chrono::microseconds microseconds_duration_of_last_tick_;
	std::chrono::microseconds microseconds_since_start_;
	std::chrono::steady_clock::time_point start_ = std::chrono::high_resolution_clock::now();
	std::chrono::steady_clock::time_point then_;
	std::chrono::steady_clock::time_point now_;
};