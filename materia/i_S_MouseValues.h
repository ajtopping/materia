#pragma once

/// <summary>
/// A singleton for storing global mouse values.
/// </summary>
/// <remarks>
/// This will become obsolete very quickly.
/// </remarks>

#include <unordered_map>
#include "amUuid.h"

class i_S_MouseValues
{
public:
	i_S_MouseValues(i_S_MouseValues const&) = delete;
	void operator=(i_S_MouseValues const&) = delete;

	static i_S_MouseValues * get_instance();
	
	static void set_mousedown(float, float);
	static void set_mouseup(float, float);
	static void set_mousehover(float, float);

	// where mouse1 was last pressed down
	float mousedown_x;
	float mousedown_y;

	// where mouse1 was last released
	float mouseup_x;
	float mouseup_y;

	// where mouse1 currently is
	float mousehover_x;
	float mousehover_y;

	// delta between current mousehover and last mousehover
	float mousetweak_x;
	float mousetweak_y;
private:
	i_S_MouseValues() {};

	static i_S_MouseValues * instance_;
};