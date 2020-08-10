
#include "rRenderLayer.h"

void rRenderLayer::Render()
{
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer_);

	util::camera::SetActiveCamera(camera_uuid_);

	entDraw::DrawScene( scene_uuid_ );
}