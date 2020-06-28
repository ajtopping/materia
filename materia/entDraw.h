#pragma once

#include "amUuid.h"
#include "am_S_Uuid_T.hpp"
#include "Component.hpp"

#include "Renderer.h"
#include "mTransform.h"

class entDraw
{
public:
	// purely static
	entDraw() = delete;
	entDraw(entDraw const&) = delete;
	void operator=(entDraw const&) = delete;

	static void Draw(amUuid);
private:
	
};