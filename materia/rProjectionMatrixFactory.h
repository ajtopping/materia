#pragma once

// SDL
#include "SDL.h"

// GLM
#include "mat4x4.hpp"
#include "ext/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"
#include "gtx/euler_angles.hpp"
#include "ext/matrix_transform.hpp"

class rProjectionMatrixFactory
{
public:
	static glm::mat4 WindowOrtho(SDL_Window *);
	static glm::mat4 WindowOrtho(int width, int height);
	static glm::mat4 WindowOrthoNdc(SDL_Window *);
	static glm::mat4 WindowOrthoNdc(int width, int height);
private:
};