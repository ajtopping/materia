#pragma once

/// <summary>
/// Static class for constructing standard ShaderProgram objects
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"

class ShaderProgramFactory
{
public:
	ShaderProgramFactory() = delete;
	ShaderProgramFactory(ShaderProgramFactory const&) = delete;
	void operator=(ShaderProgramFactory const&) = delete;

	static ShaderProgram * Uniform(const std::string resource_path);
	static ShaderProgram * NdcPanel(const std::string resource_path);
};