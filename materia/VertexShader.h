#pragma once

#include "Shader.h"

class VertexShader : public Shader
{
public:
	GLenum getType()
	{
		return GL_VERTEX_SHADER;
	}
};