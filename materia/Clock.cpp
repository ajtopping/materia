#include "Clock.h"

Clock::Clock()
{
	now_ = start_;
	//then_ = start_;
	tick();
}

void Clock::tick()
{
	then_ = now_;
	now_ = std::chrono::high_resolution_clock::now();
	microseconds_duration_of_last_tick_ = std::chrono::duration_cast<std::chrono::microseconds>(now_- then_);
	microseconds_since_start_ = std::chrono::duration_cast<std::chrono::microseconds>(now_ - start_);
}

float Clock::get_seconds_duration_of_last_tick()
{
	return (float)(microseconds_duration_of_last_tick_.count() / 1000000.0);
}

float Clock::get_seconds_duration_since_start()
{
	return (float)(microseconds_since_start_.count() / 1000000.0);
}