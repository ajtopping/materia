#pragma once

#include "mat4x4.hpp"
#include "amUuid.h"
#include "mTransform.h"
#include "rCameraProperties.h"
#include "Component.hpp"

namespace util
{
	namespace camera {
		
		static amUuid ActiveCamera = amUuid(0);

		void ClearActiveCamera();
		void SetActiveCamera(amUuid);
		glm::mat4 GetActiveCameraViewMatrix();

	}
}