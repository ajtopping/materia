#include "rPoints.h"

void rPoints::SetMesh(const mMesh& mesh)
{
	glGenVertexArrays(1, &hVao_);
	glBindVertexArray(hVao_);

	glGenBuffers(1, &hVboPosition_);
	glGenBuffers(1, &hVboColor_);

	glBindBuffer(GL_ARRAY_BUFFER, hVboPosition_);
	glBufferData(GL_ARRAY_BUFFER, mesh.getNumOfBytesPosition(), mesh.getVPosition(), GL_STATIC_DRAW);
	glVertexAttribPointer(mesh.getAPosition(), mesh.getEPosition(), GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(mesh.getAPosition());

	glBindBuffer(GL_ARRAY_BUFFER, hVboColor_);
	glBufferData(GL_ARRAY_BUFFER, mesh.getNumOfBytesColor(), mesh.getVColor(), GL_STATIC_DRAW);
	glVertexAttribPointer(mesh.getAColor(), mesh.getEColor(), GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(mesh.getAColor());

	vertex_count_ = mesh.get_vertex_count();
	triangle_count_ = mesh.get_triangle_count();
}

void rPoints::Draw(glm::mat4 mvp)
{
	if (ShaderProgramIsLinked())
	{
		shaderprogram_->useProgram();

		glBindVertexArray(hVao_);

		GLint u_mvp_loc = glGetUniformLocation(shaderprogram_->getShaderProgramUUID(), "u_mvp");
		fprintf(stdout, "Uniform loc = %d\n", u_mvp_loc);
		glUniformMatrix4fv(u_mvp_loc, 1, GL_FALSE, &mvp[0][0]);

		GLint u_runtime_in_seconds_loc = glGetUniformLocation(shaderprogram_->getShaderProgramUUID(), "u_runtime_in_seconds");
		fprintf(stdout, "u_runtime_seconds_loc = %d\n", u_runtime_in_seconds_loc);
		glUniform1f(u_runtime_in_seconds_loc, this->u_runtime_seconds_);

		GLint u_resolution_loc = glGetUniformLocation(shaderprogram_->getShaderProgramUUID(), "u_resolution");
		fprintf(stdout, "u_resolution_loc = %d\n", u_resolution_loc);
		glUniform2i(u_resolution_loc, this->u_resolution_x_, this->u_resolution_y_);

		glDrawArrays(GL_POINTS, 0, vertex_count_);
		//glDrawElements(GL_LINES, triangle_count_ * 3, GL_UNSIGNED_INT, (void*)0);
		fprintf(stdout, "vertex_count_ = %d\ntriangle_count_ = %d\n", vertex_count_, triangle_count_);
	}
	else
	{
		fprintf(stdout, "ShaderProgram was NOT linked!\n");
		// throw
	}
}
