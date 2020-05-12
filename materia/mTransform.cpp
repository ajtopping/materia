#include "mTransform.h"

glm::mat4 mTransform::get_composition_matrix()
{
	if (is_composed_ == false)
	{
		compose_matrix_();
	}

	return composition_matrix_;
}

void mTransform::compose_matrix_()
{
	glm::mat4 translate = glm::translate(glm::mat4(1.0f), pos_ );
	glm::mat4 rotate = glm::eulerAngleXYZ(rot_[0], rot_[1], rot_[2]);
	glm::mat4 scale = glm::scale(glm::mat4(1.0f), scale_);
	
	composition_matrix_ = translate * scale * rotate;

	is_composed_ = true;
}