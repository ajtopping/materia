#pragma once

/*
[MESH]Mesh
A simple container that enforces deep copied vertex data
*/

#include <GL/glew.h>
#include <cstring>
#include <iostream>

class mMesh
{
public:
	mMesh();
	~mMesh();

	void set_vertex_count(GLuint);
	void set_triangle_count(GLuint);

	void setVPosition( GLuint elementsPerVertex, const GLfloat *, size_t inData_size_in_bytes);
	void setVColor( GLuint elementsPerVertex, const GLfloat *, size_t inData_size_in_bytes);
	void setVIndex( GLuint elementsPerVertex, const GLuint *, size_t inData_size_in_bytes);

	GLuint get_vertex_count() const { return vertex_count_; }
	GLuint get_triangle_count() const { return triangle_count_; }

	GLuint getNumOfBytesPosition() const { return byteLengthPosition_; }
	GLuint getNumOfBytesColor() const { return byteLengthColor_; }
	GLuint getNumOfBytesIndex() const { return byteLengthIndex_; }

	GLfloat * getVPosition() const { return vPosition_; }
	GLfloat * getVColor() const { return vColor_; }
	GLuint * getVIndex() const { return vIndex_; }

	GLuint getEPosition() const { return ePosition_; }
	GLuint getEColor() const { return eColor_; }
	GLuint getEIndex() const { return eIndex_; }

	GLuint getAPosition() const { return aPosition_; }
	GLuint getAColor() const { return aColor_; }
	GLuint getAIndex() const { return aIndex_; }
private:
	GLuint vertex_count_ = 0;
	GLuint triangle_count_ = 0;

	GLuint byteLengthPosition_ = 0;
	GLuint byteLengthColor_ = 0;
	GLuint byteLengthIndex_ = 0;

	// [v]ectors containing each type of renderable data
	GLfloat * vPosition_ = nullptr;
	GLfloat * vColor_ = nullptr;
	GLuint * vIndex_ = nullptr;

	// [e]lements per vertex. eg 3 elements for the xyz position of a vertex
	GLuint ePosition_ = NULL;
	GLuint eColor_ = NULL;
	GLuint eIndex_ = NULL;

	// [a]ttribute index used in the shader
	GLuint aPosition_ = 0;
	GLuint aColor_ = 1;
	GLuint aIndex_ = 2;


};