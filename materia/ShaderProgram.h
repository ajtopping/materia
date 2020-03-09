#pragma once

#include <GL/glew.h>
#include <vector>

#include "Shader.h"

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	void attachShader(Shader*);
	void bindAttribLocation(GLuint index, const GLchar *);
	int linkProgram();
	void useProgram();
	void detachShader(GLuint);
	void detachAttachedShaders();
	void deleteShaderProgram();

	GLuint getShaderProgramUUID();
	int getLinkStatus();

private:
	void _createProgram();

	std::vector<GLuint> _attachedShaders;
	GLuint _shaderProgramUUID;
	int _linkStatus;
};