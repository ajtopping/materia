#pragma once

#include "mat4x4.hpp"
#include "ext/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"
#include "gtx/euler_angles.hpp"

#define GET(RETURN_TYPE, QUALIFIER, ELEMENT, INDEX) \
RETURN_TYPE QUALIFIER ## ELEMENT () const { \
return QUALIFIER ## _[INDEX]; }


#define SET(RETURN_TYPE, QUALIFIER, ELEMENT, INDEX) \
void QUALIFIER ## ELEMENT (RETURN_TYPE val) { \
QUALIFIER ## _[INDEX] = val; \
 is_composed_ = false; \
}

#define GETSET(RETURN_TYPE, QUALIFIER, ELEMENT, INDEX) \
GET(RETURN_TYPE, QUALIFIER, ELEMENT, INDEX) \
SET(RETURN_TYPE, QUALIFIER, ELEMENT, INDEX)


/// <summary>
/// Container for a Model (Position, Rotation, Scale) matrix
/// </summary>
/// <remarks>
/// Add more details here.
/// </remarks>
class mTransform
{
public:
	GETSET(float, pos, X, 0);
	GETSET(float, pos, Y, 1);
	GETSET(float, pos, Z, 2);

	GETSET(float, rot, X, 0);
	GETSET(float, rot, Y, 1);
	GETSET(float, rot, Z, 2);

	GETSET(float, scale, X, 0);
	GETSET(float, scale, Y, 1);
	GETSET(float, scale, Z, 2);

	glm::mat4 get_composition_matrix();

	glm::vec3 get_pos() { return pos_; }
	glm::vec4 get_rot() { return rot_; }
	glm::vec3 get_scale() { return scale_; }
private:
	glm::vec3 pos_ = glm::vec3(0.0f);
	glm::vec4 rot_ = glm::vec4(0.0f);
	glm::vec3 scale_ = glm::vec3(1.0f);

	glm::mat4 composition_matrix_ = glm::mat4(0.0f);

	void compose_matrix_();

	bool is_composed_ = false;
};







