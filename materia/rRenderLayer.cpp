
#include "rRenderLayer.h"

void rRenderLayer::Render()
{
	GLuint framebuffer_id = framebuffer_ < 0 ? 0 : framebuffer_;
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_id);

	// Rethink camera and projection stuff

	entDraw::DrawScene( scene_uuid_ );
}