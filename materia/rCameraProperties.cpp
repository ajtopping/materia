
#include "rCameraProperties.h"

glm::mat4 rCameraProperties::get_camera_matrix()
{
	if (is_composed_ == false)
	{
		compose_matrix_();
	}

	return composition_matrix_;
}

void rCameraProperties::compose_matrix_()
{
	composition_matrix_ = glm::perspectiveFov(fov, 1.0f, 1.0f, near_clip, far_clip);

	is_composed_ = true;
}