#pragma once

/// <summary>
/// Container for an OpenGL texture connected to a frame/depthbuffer
/// </summary>
/// <remarks>
/// 
/// </remarks>

#include <stdio.h>

#include "GL/glew.h"

class texRenderTarget
{
public:
	GLuint get_framebuffer() { return framebuffer_; }
	GLuint get_renderbuffer() { return renderbuffer_; }
	GLuint texcolorbuffer() { return texcolorbuffer_; }
private:
	GLuint framebuffer_;
	GLuint renderbuffer_;
	GLuint texcolorbuffer_;

	void initialize_();
};