#include "shGlobalUniformMap.h"

void shGlobalUniformMap::send_data_to_uniforms()
{
	GLuint sp_id;
	GLint sp_uniform_index;
	std::string uniform_name;
	shUniformBase * uniform;

	for (auto iter = address_map_.begin(); iter != address_map_.end(); iter++)
	{
		sp_id = iter->first;
		sp_uniform_index = iter->second.first;
		uniform_name = iter->second.second;

		if (uniform_map_.count(uniform_name) == 0)
		{
			fprintf(stdout, "Cannot send uniform data: the uniform name %s was not found in the GlobalUniformMap.\n", uniform_name);
		}
		else
		{
			uniform = &uniform_map_.at(uniform_name);
			uniform->send_data(UniformAddress(sp_id, sp_uniform_index));
		}
	}
}

bool shGlobalUniformMap::add_uniform_to_shaderprogram(GLuint shaderprogram_uuid, std::string uniform_name)
{
	GLint uniform_loc = glGetUniformLocation(shaderprogram_uuid, uniform_name.c_str());

	if (uniform_loc < 0)
	{
		fprintf(stdout, "Cannot add uniform to shaderprogram: the uniform name %s was not found in shaderprogram with id %d\n", uniform_name, shaderprogram_uuid);
		return false;
	}

	if (address_map_.count(shaderprogram_uuid) == 0)
	{
		address_map_.emplace(shaderprogram_uuid, std::vector<std::pair<GLint, std::string>>());
	}

	auto vec = address_map_.at(shaderprogram_uuid);
	vec.emplace_back(std::pair<GLint, std::string>(uniform_loc, uniform_name));
}

template <class T>
bool shGlobalUniformMap::update_uniform<T>(std::string uniform_name, T uniform_data)
{
	if (uniform_map_.count(uniform_name) == 0)
	{
		fprintf(stdout, "Cannot update uniform data: the uniform name %s was not found in the GlobalUniformMap.\n", uniform_name);
		return false;
	}

	shUniformT<T> uniform = uniform_map_.at(uniform_name);
	uniform.data = uniform_data;

	return true;
}