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
		glUseProgram(sp_id);
		//fprintf(stdout, "Getting ready to update uniforms in shaderprogram %u (vec size %d)\n", sp_id, iter->second.size());
		
		for (auto vec_iter = iter->second.begin(); vec_iter != iter->second.end(); vec_iter++)
		{
			sp_uniform_index = vec_iter->first;
			uniform_name = vec_iter->second;
			//fprintf(stdout, "Getting ready to update uniform %s at index %d\n", uniform_name.c_str(), sp_uniform_index);

			if (uniform_map_.count(uniform_name) == 0)
			{
				fprintf(stdout, "Cannot send uniform data: the uniform name %s was not found in the GlobalUniformMap.\n", uniform_name.c_str());
			}
			else
			{
				//fprintf(stdout, "Updating uniform %s in shaderprogram %u\n", uniform_name.c_str(), sp_id);
				uniform = uniform_map_.at(uniform_name);
				uniform->send_data(UniformAddress(sp_id, sp_uniform_index));
			}
		}
		
	}
}

bool shGlobalUniformMap::add_uniform_to_shaderprogram(GLuint shaderprogram_uuid, std::string uniform_name)
{
	GLint uniform_loc = glGetUniformLocation(shaderprogram_uuid, uniform_name.c_str());

	if (uniform_loc < 0)
	{
		fprintf(stdout, "Cannot add uniform to shaderprogram: the uniform name %s was not found in shaderprogram with id %d\n", uniform_name.c_str(), shaderprogram_uuid);
		return false;
	}

	if (address_map_.count(shaderprogram_uuid) == 0)
	{
		address_map_.emplace(shaderprogram_uuid, std::vector<std::pair<GLint, std::string>>());
	}

	address_map_.at(shaderprogram_uuid).emplace_back(std::pair<GLint, std::string>(uniform_loc, uniform_name));
	return true;
}

bool shGlobalUniformMap::add_uniform(shUniformBase * uniform_ptr)
{
	return uniform_map_.emplace(uniform_ptr->uniform_name, uniform_ptr).second;
}

