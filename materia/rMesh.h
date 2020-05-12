#pragma once

/*
Mesh Renderer
Wrapper for rendering a mesh
*/

#include "Renderer.h"
#include "mMesh.h"
#include "mTransform.h"

#include "mat3x3.hpp"
#include "ext/matrix_transform.hpp"

class rMesh : public Renderer
{
public:
	void SetMesh(const mMesh&);

	void Draw(glm::mat4 mvp);

private:
	GLuint vertex_count_ = 0;
	GLuint triangle_count_ = 0;

	// [h]andles for Vertex Buffer/Array Objects that need to be allcoated
	GLuint hVboPosition_ = NULL;
	GLuint hVboColor_ = NULL;
	GLuint hVboIndex_ = NULL;
	GLuint hVao_ = NULL;
};