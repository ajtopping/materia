#include "Camera.h"

void util::camera::ClearActiveCamera()
{
	util::camera::ActiveCamera = amUuid(0);
}

void util::camera::SetActiveCamera(amUuid camera_uuid)
{
	util::camera::ActiveCamera = camera_uuid;
}

glm::mat4 util::camera::GetActiveCameraViewMatrix()
{
	rCameraProperties * camera_ptr =  nullptr;

	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 10.0f);
	glm::vec3 right = glm::vec3(0.0f, 1.0f, 0.0f);

	if (util::HasComponent<mTransform *>(util::camera::ActiveCamera))
	{
		pos =  util::GetComponent<mTransform *>(util::camera::ActiveCamera)->get_pos();
	}
	
	if (util::HasComponent<rCameraProperties *>(util::camera::ActiveCamera))
	{
		camera_ptr = util::GetComponent<rCameraProperties *>(util::camera::ActiveCamera);
	}
	else
	{
		camera_ptr = new rCameraProperties();
	}

	glm::vec3 target = glm::vec3(pos.x, pos.y, 0.0f);

	return camera_ptr->get_camera_matrix() * glm::lookAt(pos, target, right);

}