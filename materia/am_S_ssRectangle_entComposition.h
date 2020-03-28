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

class am_S_ssRectangle_entComposition
{
public:
	am_S_ssRectangle_entComposition(am_S_ssRectangle_entComposition const&) = delete;
	void operator=(am_S_ssRectangle_entComposition const&) = delete;

	static am_S_ssRectangle_entComposition * get_instance();
	void add_datablock(std::string, dDataBlock*);
	dDataBlock * get_datablock(std::string);
private:
	am_S_ssRectangle_entComposition() {};

	std::unordered_map<std::string, dDataBlock*> data_dictionary_;

	static am_S_ssRectangle_entComposition * instance_;
};

