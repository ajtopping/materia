#pragma once

/// <summary>
/// Container for values relevant to cameras
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include "GL/glew.h"

class rCamera
{
public:
	GLfloat fov = 75.0f;
	GLfloat near_clip = 0.01f;
	GLfloat far_clip = 1000.0f;
private:
};