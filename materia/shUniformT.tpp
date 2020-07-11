#include "shUniformT.h"

// TODO: glGetError to determine return bool

template <class T>
bool shUniformT<T>::use_program_and_send_data(UniformAddress address)
{
	glUseProgram(address.first);
	return send_data(address);
}

bool shUniformT<GLint>::send_data(UniformAddress address)
{
	glUniform1i(address.second, data);
	return true;
}

bool shUniformT<GLfloat>::send_data( UniformAddress address )
{
	glUniform1f( address.second, data );
	return true;
}

bool shUniformT<glm::ivec2>::send_data( UniformAddress address )
{
	glUniform2i(address.second, data.x, data.y);
	return true;
}

bool shUniformT<glm::mat4x4>::send_data( UniformAddress address )
{
	glUniformMatrix4fv(address.second, 1, GL_FALSE, &data[0][0]);
	return true;
}