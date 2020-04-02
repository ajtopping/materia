#pragma once

#include <unordered_map>

#include "amUuid.h"

template <class T>
class amUuid_T
{
public:
	void insert(amUuid, T*);
	T * find(amUuid);
private:
	std::unordered_map<amUuid, T*, amUuidHasher> dictionary_;
};