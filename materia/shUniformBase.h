#pragma once

#include <utility>
#include <string>

#include "GL\glew.h"
#include "SDL_opengl.h"

#include "vec2.hpp"
#include "mat4x4.hpp"

typedef std::pair<GLuint, GLint> UniformAddress;

class shUniformBase
{
public:
	std::string uniform_name;

	virtual bool use_program_and_send_data(UniformAddress) = 0;
	virtual bool send_data(UniformAddress) = 0;
private:
};