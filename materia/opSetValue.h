#pragma once

template <typename T>
class opSetValue
{
public:
	T * value_ptr = nullptr;
	T * setter_ptr = nullptr;

	bool eval();
private:
};