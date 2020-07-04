#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <utility>

#include "GL\glew.h"
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
	std::unordered_map<std::string, shUniformBase> uniform_map_;
	std::unordered_map<GLuint, std::vector<std::pair<GLint, std::string>>> address_map_;
};