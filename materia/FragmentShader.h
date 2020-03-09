#pragma once

#include "Shader.h"

class FragmentShader : public Shader
{
public:
	GLenum getType()
	{
		return GL_FRAGMENT_SHADER;
	}
};