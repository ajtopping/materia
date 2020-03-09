#include "Shader.h"

Shader::Shader()
{

}

Shader::Shader(std::string path)
{
	setPath(path);
}

void Shader::setPath(std::string path)
{
	_path = path;
}

Shader::~Shader()
{
	deleteShader();
}

std::string Shader::getPath()
{
	return _path;
}

GLuint Shader::getShaderUUID()
{
	return _shaderUUID;
}

void Shader::compileShader()
{
	GLchar * source;
	int IsCompiled_VS;
	int maxLength;
	char * infoLog;

	/* Read vertex shader into an appropriate buffer */
	try {
		// check if _path is set
		source = filetobuf(_path.c_str());

		/* Create an empty vertex shader handle */
		_shaderUUID = glCreateShader(getType());

		/* Send the vertex shader source code to GL */
		/* Note that the source code is NULL character terminated. */
		/* GL will automatically detect that therefore the length info can be 0 in this case (the last parameter) */
		glShaderSource(_shaderUUID, 1, (const GLchar**)&source, 0);

		/* Compile the vertex shader */
		glCompileShader(_shaderUUID);

		glGetShaderiv(_shaderUUID, GL_COMPILE_STATUS, &IsCompiled_VS);
		if (IsCompiled_VS == false)
		{
			glGetShaderiv(_shaderUUID, GL_INFO_LOG_LENGTH, &maxLength);

			/* The maxLength includes the NULL character */
			infoLog = (char *)malloc(maxLength);

			glGetShaderInfoLog(_shaderUUID, maxLength, &maxLength, infoLog);

			/* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
			/* In this simple program, we'll just leave */
			free(infoLog);
			free(source);
			return;
		}

		free(source);
	}
	catch (missing_resource_error& e) {
		fprintf(stdout, e.what());
		return;
		// terminate
	}
}

void Shader::deleteShader()
{
	// check if exists first
	glDeleteShader(_shaderUUID);
}