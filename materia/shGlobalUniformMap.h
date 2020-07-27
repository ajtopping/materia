#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

#include <GL/glew.h>
#include "SDL_opengl.h"

#include "shUniformT.h"
#include "ShaderProgram.h"

class shGlobalUniformMap
{
public:
	void send_data_to_uniforms();
	bool add_uniform_to_shaderprogram(GLuint, std::string);
	bool add_uniform(shUniformBase *);

	template <class T>
	bool update_uniform(std::string, T);
private:
	std::unordered_map<std::string, shUniformBase*> uniform_map_;

	// Maps a shaderprogram uuid to a list of uniform location/name pairs
	std::unordered_map<GLuint, std::vector<std::pair<GLint, std::string>>> address_map_;
};

template <class T>
bool shGlobalUniformMap::update_uniform(std::string uniform_name, T uniform_data)
{
	if (uniform_map_.count(uniform_name) == 0)
	{
		fprintf(stdout, "Cannot update uniform data: the uniform name %s was not found in the GlobalUniformMap.\n", uniform_name.c_str());
		return false;
	}

	shUniformT<T> * uniform = dynamic_cast<shUniformT<T>*>(uniform_map_.at(uniform_name));
	uniform->data = uniform_data;

	return true;
}