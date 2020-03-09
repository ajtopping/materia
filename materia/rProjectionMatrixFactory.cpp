#include "rProjectionMatrixFactory.h"

glm::mat4 rProjectionMatrixFactory::WindowOrtho(SDL_Window * sdl_window_ptr)
{
	int w, h;
	SDL_GL_GetDrawableSize(sdl_window_ptr, &w, &h);
	return rProjectionMatrixFactory::WindowOrtho(w, h);
}

glm::mat4 rProjectionMatrixFactory::WindowOrtho(int width, int height)
{
	return glm::ortho(0.f, static_cast<float>(width), 0.f,static_cast<float>(height), -1.f, 1.f);
}

glm::mat4 rProjectionMatrixFactory::WindowOrthoNdc(SDL_Window * sdl_window_ptr)
{
	int w, h;
	SDL_GL_GetDrawableSize(sdl_window_ptr, &w, &h);
	return rProjectionMatrixFactory::WindowOrthoNdc(w, h);
}

glm::mat4 rProjectionMatrixFactory::WindowOrthoNdc(int width, int height)
{
	//return glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, -1.f, 1.f);
	return glm::ortho(0.0f, 320.0f, 0.0f, 240.0f, -1.f, 1.f);
}