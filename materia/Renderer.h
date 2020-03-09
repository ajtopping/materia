#pragma once

/*
Renderer interface
Can be used for rendering raw GLSL
*/

#include "ShaderProgram.h"
#include "mTransfrom.h"
#include "rProjectionMatrixFactory.h"

#include "mat3x3.hpp"
#include "ext/matrix_transform.hpp"

class Renderer
{
public:
	void SetShaderProgram(ShaderProgram *);
	void set_u_runtime_seconds(GLfloat runtime_seconds) { u_runtime_seconds_ = runtime_seconds; };
	void set_u_resolution(GLuint resolution_x, GLuint resolution_y)
	{
		u_resolution_x_ = resolution_x; u_resolution_y_ = resolution_y;
	}
	void set_projection_matrix(glm::mat4);

	int ShaderProgramIsLinked();
	void Draw();
	virtual void Draw(glm::mat4 mvp) = 0;
	

protected:
	GLfloat u_runtime_seconds_ = 0.0;
	GLuint u_resolution_x_ = 1;
	GLuint u_resolution_y_ = 1;

	glm::mat4 projection_matrix_ = rProjectionMatrixFactory::WindowOrtho(64, 64);

	ShaderProgram * shaderprogram_ = nullptr;
};