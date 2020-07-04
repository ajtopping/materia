#include "shUniformT.h"

template <class T>
bool shUniformT<T>::use_program_and_send_data(UniformAddress address)
{
	glUseProgram(address.first);
	send_data(address);
}

bool shUniformT<GLfloat>::send_data( UniformAddress address )
{
	glUniform1f( address.second, data );
}

bool shUniformT<glm::ivec2>::send_data( UniformAddress address )
{
	glUniform2i(address.second, data.x, data.y);
}

bool shUniformT<glm::mat4x4>::send_data( UniformAddress address )
{
	glUniformMatrix4fv(address.second, 1, GL_FALSE, &data[0][0]);
}