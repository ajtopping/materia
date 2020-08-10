#pragma once

/// <summary>
/// The highest level class for rendering. Renders an entScene using an rCamera [optional] to a specified framebuffer [optional]
/// </summary>
/// <remarks>
/// Renders to the default framebuffer (id = 0) if no other is specified.
/// </remarks>

#include "GL/glew.h"

#include "amUuid.h"
#include "entDraw.h"
#include "Camera.h"

class rRenderLayer
{
public:
	void Render();

	void set_scene_uuid(amUuid uuid) { scene_uuid_ = uuid; }
	void set_camera_uuid(amUuid uuid) { camera_uuid_ = uuid; }
	void set_framebuffer(GLuint id) { framebuffer_ = id; }
private:
	amUuid scene_uuid_ = amUuid(0);
	amUuid camera_uuid_ = amUuid(0);
	GLuint framebuffer_ = 0;

};