#pragma once

/// <summary>
/// Container for values relevant to cameras
/// </summary>
/// <remarks>
/// The mTransform component will be used if one is found BUT the scale and rotation data will be ignored in favor of always
/// looking down the forward vector given by vec3( 0, 0, -1 )
/// </remarks>

#include "am_HasUuidRegistryTicket.h"

#include "GL/glew.h"
#include "mat4x4.hpp"
#include "ext/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"
#include "gtx/euler_angles.hpp"
#include "gtx/projection.hpp"

#include "Component.hpp"
#include "amUuid.h"
#include "mTransform.h"

class rCameraProperties : public am_HasUuidRegistryTicket
{
public:
	glm::mat4 get_camera_matrix();
	
	GLfloat fov = 75.0f;
	GLfloat near_clip = 0.01f;
	GLfloat far_clip = 1000.0f;

	void make_dynamic_cast_happy() {};
private:
	void compose_matrix_();

	bool is_composed_ = false;
	glm::mat4 composition_matrix_;

	amUuid uuid_;
};