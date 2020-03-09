#include "mMesh.h"

mMesh :: mMesh()
{
	fprintf(stdout, "Constructing mMesh\n");
}

mMesh::~mMesh()
{
	fprintf(stdout, "Deconstructing mMesh\n");
	delete[](vPosition_);
	delete[](vColor_);
	delete[](vIndex_);
}

void mMesh::set_vertex_count(GLuint vertex_count)
{
	vertex_count_ = vertex_count;
}

void mMesh::set_triangle_count(GLuint triangle_count)
{
	triangle_count_ = triangle_count;
}

void mMesh::setVPosition(GLuint elementsPerVertex, const GLfloat * inData, size_t inData_size_in_bytes)
{
	ePosition_ = elementsPerVertex;
	delete[](vPosition_);
	size_t arr_length = inData_size_in_bytes / sizeof(GLfloat);
	vPosition_ = new GLfloat[arr_length];
	byteLengthPosition_ = arr_length * sizeof(GLfloat);
	memcpy(vPosition_, inData, inData_size_in_bytes);
}

void mMesh::setVColor(GLuint elementsPerVertex, const GLfloat * inData, size_t inData_size_in_bytes)
{
	eColor_ = elementsPerVertex;
	delete[](vColor_);
	size_t arr_length = inData_size_in_bytes / sizeof(GLfloat);
	vColor_ = new GLfloat[arr_length];
	byteLengthColor_ = arr_length * sizeof(GLfloat);
	memcpy(vColor_, inData, inData_size_in_bytes);
}

void mMesh::setVIndex(GLuint elementsPerVertex, const GLuint * inData, size_t inData_size_in_bytes)
{
	eIndex_ = elementsPerVertex;
	delete[](vIndex_);
	size_t arr_length = inData_size_in_bytes / sizeof(GLuint);
	vIndex_ = new GLuint[arr_length];
	byteLengthIndex_ = arr_length * sizeof(GLuint);
	memcpy(vIndex_, inData, inData_size_in_bytes);
}
