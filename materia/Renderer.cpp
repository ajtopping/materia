#include "Renderer.h"

void Renderer::SetShaderProgram(ShaderProgram * shaderprogram)
{
	shaderprogram_ = shaderprogram;
}

int Renderer::ShaderProgramIsLinked()
{
	GLint link_status = 0;
	int maxLength;
	char *shaderProgramInfoLog;
	GLuint shaderprogram_uuid = shaderprogram_->getShaderProgramUUID();
	glGetProgramiv(shaderprogram_uuid, GL_LINK_STATUS, &link_status);
	
	return link_status;
}

void Renderer::Draw()
{
	glm::mat4 mvp = projection_matrix_ * glm::translate(glm::mat4(1.f), glm::vec3(0.0f, 0.0f, 0.0f)) * glm::scale(glm::mat4(1.f), glm::vec3(100.f));
	Draw(mvp);
}

void Renderer::set_projection_matrix(glm::mat4 projection_matrix)
{
	projection_matrix_ = projection_matrix;
}