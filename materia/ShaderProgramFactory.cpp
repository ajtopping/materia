#include "ShaderProgramFactory.h"

ShaderProgram * ShaderProgramFactory::Uniform(const std::string resource_path)
{
	VertexShader vs;
	std::string vertexsourcepath = resource_path + "\\shaders\\uniform.vert";
	vs.setPath(vertexsourcepath);
	vs.compileShader();

	FragmentShader fs;
	std::string fragmentsourcepath = resource_path + "\\shaders\\uniform.frag";
	fs.setPath(fragmentsourcepath);
	fs.compileShader();

	ShaderProgram * shaderProgram = new ShaderProgram();

	shaderProgram->attachShader(&vs);
	shaderProgram->attachShader(&fs);

	shaderProgram->bindAttribLocation(0, "in_Position");
	shaderProgram->bindAttribLocation(1, "in_Color");

	return shaderProgram;
}

ShaderProgram * ShaderProgramFactory::NdcPanel(const std::string resource_path)
{
	VertexShader vsNdcPanel;
	std::string vertexsourcepath = resource_path + "\\shaders\\ndcPanel.vert";
	vsNdcPanel.setPath(vertexsourcepath);
	vsNdcPanel.compileShader();

	FragmentShader fsNdcPanel;
	std::string fragmentsourcepath = resource_path + "\\shaders\\ndcPanel.frag";
	fsNdcPanel.setPath(fragmentsourcepath);
	fsNdcPanel.compileShader();

	ShaderProgram * shaderProgram = new ShaderProgram();;

	shaderProgram->attachShader(&vsNdcPanel);
	shaderProgram->attachShader(&fsNdcPanel);

	shaderProgram->bindAttribLocation(0, "in_Position");
	shaderProgram->bindAttribLocation(1, "in_TexCoords");

	return shaderProgram;
}