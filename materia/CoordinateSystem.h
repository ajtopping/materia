#pragma once

#include "glm.hpp"

enum COORDSYS2D
{
	CARTESIAN,
	SDLWINDOW,
	NDC,
};

namespace util
{
	class CoordinateSystem
	{
	public:
		static glm::vec2 Convert2D( glm::vec2, COORDSYS2D, COORDSYS2D);
	};
}