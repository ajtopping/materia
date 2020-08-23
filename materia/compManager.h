#pragma once

/// <summary>
/// Manages the storage of the lifetime of a component.
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "amUuid.h"
#include "am_Uuid_T.hpp"

template <class T>
class compMananger
{
public:
	amUuid NewComponent();
	bool DeleteComponent( amUuid );
private:
	am_Uuid_T<T> tmap_;
};