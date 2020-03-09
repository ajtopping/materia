#pragma once

#include "GL\glew.h"

#include <string>
#include "filetobuf.h"
#include "missing_resource_error.h"

class Shader
{
public:
	Shader();
	~Shader();
	Shader( std::string path );
	void setPath(std::string path);
	std::string getPath();
	GLuint getShaderUUID();
	void compileShader();
	void deleteShader();
	virtual GLenum getType() = 0;
private:
	std::string _path;
	GLuint _shaderUUID;
};