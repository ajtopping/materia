#include "i_S_MouseValues.h"

i_S_MouseValues * i_S_MouseValues::instance_ = nullptr;

i_S_MouseValues * i_S_MouseValues::get_instance()
{
	if (!instance_)
	{
		instance_ = new i_S_MouseValues();
	}
	return instance_;
}

void i_S_MouseValues::set_mousedown(float x, float y)
{
	i_S_MouseValues::get_instance()->mousedown_x = x;
	i_S_MouseValues::get_instance()->mousedown_y = y;
}

void i_S_MouseValues::set_mouseup(float x, float y)
{
	i_S_MouseValues::get_instance()->mouseup_x = x;
	i_S_MouseValues::get_instance()->mouseup_y = y;
}

void i_S_MouseValues::set_mousehover(float x, float y)
{
	i_S_MouseValues::get_instance()->mousetweak_x = x - i_S_MouseValues::get_instance()->mousehover_x;
	i_S_MouseValues::get_instance()->mousetweak_y = y - i_S_MouseValues::get_instance()->mousehover_y;

	i_S_MouseValues::get_instance()->mousehover_x = x;
	i_S_MouseValues::get_instance()->mousehover_y = y;
}