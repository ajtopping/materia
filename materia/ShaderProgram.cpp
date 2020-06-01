#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	_createProgram();
}

ShaderProgram::~ShaderProgram()
{
	detachAttachedShaders();
	deleteShaderProgram();
}

void ShaderProgram::_createProgram()
{
	_shaderProgramUUID = glCreateProgram();
}

void ShaderProgram::attachShader(Shader * shader)
{
	glAttachShader(getShaderProgramUUID(), shader->getShaderUUID());

	// TODO check if successfully attached

	_attachedShaders.push_back(shader->getShaderUUID());
}

void ShaderProgram::bindAttribLocation(GLuint index, const GLchar * name)
{
	glBindAttribLocation(getShaderProgramUUID(), index, name);
}

int ShaderProgram::linkProgram()
{
	glLinkProgram(getShaderProgramUUID());

	int maxLength;
	char *shaderProgramInfoLog;
	glGetProgramiv(getShaderProgramUUID(), GL_LINK_STATUS, (int *)&_linkStatus);
	if (_linkStatus == false)
	{
		/* Noticed that glGetProgramiv is used to get the length for a shader program, not glGetShaderiv. */
		glGetProgramiv(getShaderProgramUUID(), GL_INFO_LOG_LENGTH, &maxLength);

		/* The maxLength includes the NULL character */
		shaderProgramInfoLog = (char *)malloc(maxLength);

		/* Notice that glGetProgramInfoLog, not glGetShaderInfoLog. */
		glGetProgramInfoLog(getShaderProgramUUID(), maxLength, &maxLength, shaderProgramInfoLog);

		/* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
		/* In this simple program, we'll just leave */
		free(shaderProgramInfoLog);
	}

	// the internet says to detach shaders after linking
	detachAttachedShaders();

	return _linkStatus;
}

void ShaderProgram::useProgram()
{
	glUseProgram(getShaderProgramUUID());
}

void ShaderProgram::detachShader(GLuint shaderUUID)
{
	glDetachShader(getShaderProgramUUID(), shaderUUID);
}

void ShaderProgram::detachAttachedShaders()
{
	for (std::vector<GLuint>::iterator iter = _attachedShaders.begin(); iter != _attachedShaders.end(); ++iter)
	{
		fprintf(stdout, "ShaderProgram: Detaching shader: %d\n", *iter);
		detachShader(*iter);
	}
}

void ShaderProgram::deleteShaderProgram()
{
	// TODO check if already deleted

	glDeleteProgram(getShaderProgramUUID());
}

GLuint ShaderProgram::getShaderProgramUUID()
{
	return _shaderProgramUUID;
}

int ShaderProgram::getLinkStatus()
{
	return _linkStatus;
}
