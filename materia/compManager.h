#pragma once

/// <summary>
/// Manages the storage of the lifetime of a component.
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amUuid.h"
#include "amUuid_T.hpp"

template <class T>
class compMananger
{
public:
	amUuid NewComponent();
	bool DeleteComponent( amUuid );
private:
	amUuid_T<T> tmap_;
};