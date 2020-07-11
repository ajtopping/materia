#pragma once

#include <utility>
#include <string>

#include "GL\glew.h"
#include "SDL_opengl.h"

#include "shUniformBase.h"
#include "vec2.hpp"
#include "mat4x4.hpp"

template <class T>
class shUniformT : public shUniformBase
{
public:
	shUniformT(std::string name) : shUniformBase( name ) {};

	std::string uniform_name;
	T data;

	bool use_program_and_send_data(UniformAddress);
	bool send_data(UniformAddress);
private:
};