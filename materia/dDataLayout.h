#pragma once

#include <vector>

/// <summary>
/// Describes order and size of each data chunk in the raw bits of a dDataBlock
/// </summary>
/// <remarks>
/// The order is implied by the index in the vector
/// </remarks>
struct dDataLayout
{
	dDataLayout();
	dDataLayout(std::vector<unsigned int>);

	std::vector<unsigned int> layout;
};

dDataLayout::dDataLayout()
{
	// Nothing
}

dDataLayout::dDataLayout( std::vector<unsigned int> v )
{
	layout = v;
}