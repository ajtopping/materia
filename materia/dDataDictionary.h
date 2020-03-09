#pragma once

/// <summary>
/// Describes order and size of each data chunk in the raw bits of a dDataBlock
/// </summary>
/// <remarks>
/// The order is implied by the index in the vector
/// </remarks>

#include <unordered_map>
#include <string>

#include "dDataBlock.h"

class dDataDictionary
{
public:
	dDataDictionary(dDataDictionary const&) = delete;
	void operator=(dDataDictionary const&) = delete;

	static dDataDictionary * get_instance();
	void add_datablock(std::string, dDataBlock*);
	dDataBlock * get_datablock(std::string);
private:
	dDataDictionary() {};

	std::unordered_map<std::string, dDataBlock*> data_dictionary_;

	static dDataDictionary * instance_;
};

