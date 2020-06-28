#include "rMesh.h"

void rMesh::SetMesh(const mMesh& mesh)
{
	/* Allocate and assign a Vertex Array Object to our handle */
	glGenVertexArrays(1, &hVao_);
	/* Bind our Vertex Array Object as the current used object */
	glBindVertexArray(hVao_);

	/* Allocate and assign three Vertex Buffer Objects to our handles */
	glGenBuffers(1, &hVboPosition_);
	glGenBuffers(1, &hVboColor_);
	glGenBuffers(1, &hVboIndex_);

	/* Bind buffer */
	glBindBuffer(GL_ARRAY_BUFFER, hVboPosition_);
	/* Copy data into the buffer */
	glBufferData(GL_ARRAY_BUFFER, mesh.getNumOfBytesPosition(), mesh.getVPosition(), GL_STATIC_DRAW);
	/* Specify that our coordinate data is going into attribute index 0, and contains two floats per vertex */
	glVertexAttribPointer(mesh.getAPosition(), mesh.getEPosition(), GL_FLOAT, GL_FALSE, 0, 0);
	/* Enable attribute index 0 as being used */
	glEnableVertexAttribArray(mesh.getAPosition());

	/* Bind our second VBO as being the active buffer and storing vertex attributes (colors) */
	glBindBuffer(GL_ARRAY_BUFFER, hVboColor_);
	/* Copy the color data from colors to our buffer */
	glBufferData(GL_ARRAY_BUFFER, mesh.getNumOfBytesColor(), mesh.getVColor(), GL_STATIC_DRAW);
	/* Specify that our color data is going into attribute index 1, and contains three floats per vertex */
	glVertexAttribPointer(mesh.getAColor(), mesh.getEColor(), GL_FLOAT, GL_FALSE, 0, 0);
	/* Enable attribute index 1 as being used */
	glEnableVertexAttribArray(mesh.getAColor());

	/* Bind our third VBO as being the active buffer and storing vertex attributes (indexes) */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, hVboIndex_);
	/* Copy the index data from indexes to our buffer */
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.getNumOfBytesIndex(), mesh.getVIndex(), GL_STATIC_DRAW);
	/* Index data is not important to the shader and does not need an attribute index */
	//glEnableVertexAttribArray(mesh.getAIndex());

	vertex_count_ = mesh.get_vertex_count();
	triangle_count_ = mesh.get_triangle_count();
}

void rMesh::Draw(glm::mat4 mvp)
{
	if (ShaderProgramIsLinked())
	{
		shaderprogram_->useProgram();

		glBindVertexArray(hVao_);

		GLint u_mvp_loc = glGetUniformLocation(shaderprogram_->getShaderProgramUUID(), "u_mvp");
		//fprintf(stdout, "Uniform loc = %d\n", u_mvp_loc);
		glUniformMatrix4fv(u_mvp_loc, 1, GL_FALSE, &mvp[0][0]);

		GLint u_runtime_in_seconds_loc = glGetUniformLocation(shaderprogram_->getShaderProgramUUID(), "u_runtime_in_seconds");
		//fprintf(stdout, "u_runtime_seconds_loc = %d\n", u_runtime_in_seconds_loc);
		glUniform1f(u_runtime_in_seconds_loc, this->u_runtime_seconds_);

		GLint u_resolution_loc = glGetUniformLocation(shaderprogram_->getShaderProgramUUID(), "u_resolution");
		//fprintf(stdout, "u_resolution_loc = %d\n", u_resolution_loc);
		glUniform2i(u_resolution_loc, u_resolution_x_, u_resolution_y_);

		//glDrawArrays(GL_POINTS, 0, vertex_count_);
		glDrawElements(GL_TRIANGLES, triangle_count_ * 3, GL_UNSIGNED_INT, (void*)0);
		//fprintf(stdout, "vertex_count_ = %d\ntriangle_count_ = %d\n", vertex_count_, triangle_count_);

		glBindVertexArray(0);
	}
	else
	{
		fprintf(stdout, "ShaderProgram was NOT linked!\n");
		// throw
	}
}
